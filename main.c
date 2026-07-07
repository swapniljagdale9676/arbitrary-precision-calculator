/*
Name          : Swapnil Jagdale
Date          : 23/01/2026
Project Title : APC - Arbitrary Precision Calculator
Description   :	 Standard integer types (int, long, long long) have fixed ranges and overflow for large numbers. 
*                The Arbitrary Precision Calculator (APC) overcomes this limitation by storing numbers digit-wise 
*                and performing arithmetic operations manually (like on paper).
*                The APC supports integer values of unlimited length and operations 
*                like addition, subtraction, multiplication, division and modulus.
*/
#include "apc.h"

int main(int argc, char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *res_head = NULL, *res_tail = NULL;
	char option, operator;

	/* For validating input*/
	if(validation_input(argc, argv) == FAILURE)
	{
		return 0;
	}

	int sign1 = 1, sign2 = 1;

	/* Convert strings to linked list */
	/* Handle sign for operand 1 */
	if(argv[1][0] == '-')
	{
		sign1 = -1;
		string_to_list(argv[1] + 1, &head1, &tail1);
	}
	else if(argv[1][0] == '+')
	{
		string_to_list(argv[1] + 1, &head1, &tail1);
	}
	else
	{
		string_to_list(argv[1], &head1, &tail1);
	}

	/* Handle sign for operand 2 */
	if(argv[3][0] == '-')
	{
		sign2 = -1;
		string_to_list(argv[3] + 1, &head2, &tail2);     	// Function call
	}
	else if(argv[3][0] == '+')        
	{
		string_to_list(argv[3] + 1, &head2, &tail2);
	}
	else
	{
		string_to_list(argv[3], &head2, &tail2);
	}
	/* For removing leading zero's */
	removing_leading_zeros(&head1, &tail1);
	removing_leading_zeros(&head2, &tail2);

	/* Extract operator */
	operator = argv[2][0];

	printf("\033[1mOperand1 : \033[1m%s", (sign1 == -1 ? "-" : ""));
	print_list(head1);
	printf("\033[1mOperand2 : \033[1m%s", (sign2 == -1 ? "-" : ""));
	print_list(head2);
	printf("Operator : %c\n", operator);

	switch(operator)
	{
		/* Case for the Addition operator */
		case '+':
			if(sign1 != sign2)
			{
				int cmp = compare(head1, head2);    // Comparing the lengths 
				if(cmp == 0)
				{
					/* If equal then result = 0 */
					dll_insert_last(&res_head, &res_tail, 0);
					sign1 = 1;    // '0' is always positive
				}
				else if(cmp > 0)     // If head1 > head2 -> head1 - head2
				{
					subtraction(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
					sign1 = sign1; 	// Result sign = sign of bigger number
				}
				else
				{
					// if head1 < head2 -> head2 -head1
					subtraction(&head2, &tail2, &head1, &tail1, &res_head, &res_tail);
					sign1 = sign2;    // Bigger number sign
				}
			}
			else
			{
				/* Same sign = Normal addition */
				addition(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
				/* Result sign is same as sign1 or sign2 */
			}

			print_result(sign1, res_head);
			break;
		
		/* Case for the Subtraction operator */
		case '-':
			/* Same sign subtraction will take place */
			if (sign1 == sign2)
			{
				// (-A) - (-B) || (+A) - (+B)
				int cmp = compare(head1, head2);
				// If head1 = head2
				if(cmp == 0)
				{
					// Result = 0
					dll_insert_last(&res_head, &res_tail, 0);
					sign1 = 1;
				}
				else if(cmp > 0)
				{
					// If head1 > head2 -> head1 - head2
					subtraction(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
					if(sign1 == -1)   // if head1 is bigger then sign will be of bigger
						sign1 = -1;
					else 
						sign1 = 1;
				}
				else 
				{
					// If head1 < head2 -> head2 - head1
					subtraction(&head2, &tail2, &head1, &tail1, &res_head, &res_tail);
					// If operand2 is bigger then sign will be change
					if(sign1 == -1)
						sign1 = 1;
					else 
						sign1 = -1;					
				}
			}
			/* If differnt sign then subtraction will take place */
			else
			{
				/* If the sign is differ (sign1 != sign2) */
				addition(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
				// if head1 sign is '-'
				if(sign1 == -1)
					sign1 = -1;
				else
					sign1 = 1;				
			}

			print_result(sign1, res_head);
			break;

		/* Case for the Multiplication operator */
		case 'x':
			/* If any one operand = 0 */
			if(is_zero(head1, tail1) || is_zero(head2, tail2))
			{
				dll_insert_first(&res_head, &res_tail, 0);  // insert zero as the first node in result list
				print_result(1, res_head);
				break;
			}
			multiplication(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
			print_result(sign1 * sign2, res_head);
			break;
		/* Case for the Division operator */
		case '/':
			/* Check Operand2 is 0 */
			if(is_zero(head2, tail2))
			{
				printf("\033[1;31mError :\033[0m cannot Divide by zero!\n");
				break;
			}
			/* Check if Operand1 is 0 */
			if(is_zero(head1, tail1))
			{
				dll_insert_first(&res_head, &res_tail, 0);    // Directly insert '0' in the result list
				print_result(1, res_head);
				break;
			}

			division(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);	
			print_result(sign1 * sign2, res_head);
			break;

		case '%':

			/* Check Operand2(divisor) = 0 */
			if(is_zero(head2, tail2))
			{
				printf("\033[1;31mError :\033[0m cannot Modulo by zero!\n");
				return FAILURE;
			}
			/* Check if Operand1 is 0 */
			else if(is_zero(head1, tail1))
			{
				dll_insert_first(&res_head, &res_tail, 0);    // Directly insert '0' in the result list
				print_result(1, res_head);
				break;
			}
			modulus(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
			if(res_head->data == 0 && res_head->next == NULL && res_tail == res_head)
			{
				print_result(1, res_head);
				break;
			}
			print_result(sign1, res_head);
			break;

		default:
			printf("\033[1;31mError :\033[0m Invalid operator!\n");
	}

	return 0;
}