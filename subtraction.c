/*
*Title			    : Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		    : int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
		:     tail1 : Pointer to the last node of the first double linked list.
		:     head2 : Pointer to the first node of the second double linked list.
		:     tail2 : Pointer to the last node of the second double linked list.
		:  res_head : Pointer to the first node of the resultant double linked list.
		:  res_tail : Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,
				Dlist **head2, Dlist **tail2, 
				Dlist **res_head, Dlist **res_tail)
{
	/* Starts p1 and p2 from the tails i.e Least significant byte */
	Dlist *p1 = *tail1;
	Dlist *p2 = *tail2;
	/* Borrow to take if the tail1 is less than tail2 */
	int borrow = 0;
	// Loop runs until all of them becomes NULL / 0
	while(p1 || p2 || borrow)
	{
		/* If node is present, use its digit else consider digit as zero(0) */
		int d1 = (p1) ? p1->data : 0;
		int d2 = (p2) ? p2->data : 0;
		/* For subtracting the borrow from the next node if taken */
		d1 = d1 - borrow;
		/* If the d1 < d2 take borrow means add 10 to the d1 */
		if(d1 < d2)
		{
			d1 += 10;
			borrow = 1;   /* Set borrow for further iteration */
		}
		else
			borrow = 0;    /* Set borrow as '0' */
		/* Actual subtraction */
		int digit = d1 - d2;    
		/* Insert digit at the beginning  */
		dll_insert_first(res_head, res_tail, digit);
		/* Traversal Both pointers to the left towards MSD */
		if(p1)
			p1 = p1->prev;
		if(p2)
			p2 = p2->prev;

	}
	/* For removing trailing zeros at the beginning */
	removing_leading_zeros(res_head, res_tail);    

	return SUCCESS;
}