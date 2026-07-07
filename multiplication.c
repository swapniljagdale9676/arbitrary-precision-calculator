/*
*Title			    : Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		    : int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
		 :    tail1 : Pointer to the last node of the first double linked list.
		 :    head2 : Pointer to the first node of the second double linked list.
		 :    tail2 : Pointer to the last node of the second double linked list.
		 : res_head : Pointer to the first node of the resultant double linked list.
		 : res_tail : Pointer to the last node of the resultant double linked list.
*Output			    : Status (SUCCESS / FAILURE)
*/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail)
{
	/* Take three list for multiplication i.e needed to store the result after iteration */
	Dlist *op1_head = NULL, *op1_tail = NULL;
	Dlist *op2_head = NULL, *op2_tail = NULL;
	Dlist *final_head = NULL, *final_tail = NULL;

	Dlist *p1, *p2 = *tail2;
	int zero_count = 0;

	while(p2)
	{
		int carry = 0;
		op2_head = NULL,op2_tail = NULL;
		/* Iff first iteration is completed add 0 as per multiplication rule */
		for(int j = 0; j < zero_count; j++)
		{
			if(dll_insert_first(&op2_head, &op2_tail, 0) == FAILURE)
			return FAILURE;
		}
		/* After first iteration p1 must again start from the first */
		p1 = *tail1;
		/* Continuing loop until one of (p1) or (Carry) is NUll/'0' */
		while(p1)
		{
			/* To perform the operation */
			int prod = (p1->data * p2->data) + carry;      // Performing the operation
			int digit = prod % 10;      // For getting number which will be at the unit place
			carry = prod / 10;			// Carry will be always as quotient

			/* Insertinf the digit into the list */
			if(dll_insert_first(&op2_head, &op2_tail, digit) == FAILURE)
			return FAILURE;
			// Traversing node to the prev node
			p1 = p1->prev;    
		}
		/* If carry remains after the each iteration */
		if(carry)
		{
			if(dll_insert_first(&op2_head, &op2_tail, carry) == FAILURE)
			{
				return FAILURE;
			}
		}

		/* First product copy directly to the op1 list */
		if(op1_head == NULL)
		{
			op1_head = op2_head;
			op1_tail = op2_tail;
		}
		else 
		{
			/* Adding op1 + op2 -> Final, for getting final list  */
			final_head = final_tail = NULL;
			
			addition(&op1_head, &op1_tail, &op2_head, &op2_tail, &final_head, &final_tail);
			/* Free the two product list */
			dll_delete_list(&op1_head, &op1_tail);
			dll_delete_list(&op2_head, &op2_tail);
			/* Again store the final list to the op1 list */
			op1_head = final_head;
			op1_tail = final_tail;
		}
		// Traversing p2 to the left towards MSB
		p2 = p2->prev; 
		zero_count++;     // For the next iteration to insert the zero at end in the linked list 
	}
	/* Update the result list by op1->head and op1->tail */
	*res_head = op1_head;
	*res_tail = op1_tail;

	return SUCCESS;
}