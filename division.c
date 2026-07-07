/*
*Title			    : Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		    : int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
		 :    tail1 : Pointer to the last node of the first double linked list.
		 :    head2 : Pointer to the first node of the second double linked list.
		 :    tail2 : Pointer to the last node of the second double linked list.
		 : res_head : Pointer to the first node of the resultant double linked list.
		 : res_tail : Pointer to the last node of the resultant double linked list.

*Output			    : Status (SUCCESS / FAILURE)
*/
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail)
{
	/* Temporary list for storing the dividend */
	Dlist *new_head = NULL, *new_tail = NULL;
	Dlist *temp = *head1;      // temp initialized as head1(address) for accessing all the elements of operand1

	while(temp)
	{
		/* To append the next digit to dividend */
		dll_insert_last(&new_head, &new_tail, temp->data);  
		/* For removing the leading zeros from the dividend */   
		removing_leading_zeros(&new_head, &new_tail);

		int count = 0;
		/* Loop will continue until the dividend >= divisor */
		while(compare(new_head, *head2) >= 0)
		{
			/* List for storing subtraction result */
			Dlist *subt_head = NULL, *subt_tail = NULL;
			// Function call for Dividend - Divisor
			subtraction(&new_head, &new_tail, head2, tail2, &subt_head, &subt_tail);
			/* For deleting partially stored dividend */
			dll_delete_list(&new_head, &new_tail);
			/* Store the Subtraction result as temporary dividend */
			new_head = subt_head;
			new_tail = subt_tail;
			/* For removing the leading zeros from the dividend */   
			removing_leading_zeros(&new_head, &new_tail);
			/* Count for how many times divisor was subtracted */
			count++;
		}
		/* Appending next quotient if dividend is less than divisor as '0' */
		dll_insert_last(res_head, res_tail, count);
		/* For moving the original dividend to next digit*/
		temp = temp->next;
	}
	/* Removing leading zeros from the final quotient */
	removing_leading_zeros(res_head, res_tail);
	/* Free the temporary dividend*/
	dll_delete_list(&new_head, &new_tail);

	return SUCCESS;
}
