/*
*Title			    : Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		    : int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
		:      tail1: Pointer to the last node of the first double linked list.
		:      head2: Pointer to the first node of the second double linked list.
		:      tail2: Pointer to the last node of the second double linked list.
		:  res_head : Pointer to the first node of the resultant double linked list.
		:  res_tail : Pointer to the first node of the resultant double linked list.

*Output			    : Status (SUCCESS / FAILURE)
*/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **res_head, Dlist **res_tail)
{
	/* Starts p1 and p2 from the tails i.e Least significant byte */
    Dlist *p1 = *tail1;    
    Dlist *p2 = *tail2;	
	/* Carry to handle sums above 9 */	 
    int carry = 0;      
	/* Continue until both list reaches NULL and no carry is remaining  */
    while (p1 || p2 || carry)
    {
		/* If node is present, use its digit else consider digit as zero(0) */
        int d1 = (p1) ? p1->data : 0;        
        int d2 = (p2) ? p2->data : 0;
		/* Add the two digits with the carry */
        int sum = d1 + d2 + carry;
		/* Store the digit at unit place and carry to compute */
        int digit = sum % 10;       
        carry = sum / 10;
		/* Insert the digit at the beginning */
        dll_insert_first(res_head, res_tail, digit);
		/* Traverse to the left towards MSD */
        if (p1) 
		p1 = p1->prev;    // Traversal from the last towards MSB

        if (p2) 
		p2 = p2->prev;    // Traversal from the last towards MSB
    }

    return SUCCESS;
}
