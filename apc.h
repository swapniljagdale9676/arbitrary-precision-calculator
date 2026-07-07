#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Included the prototypes here */

/* For the validation of the CLA Arguments */
int validation_input(int argc, char *argv[]);

/* Conversion of string to the Linked list*/
int string_to_list(char *str, Dlist **head, Dlist **tail);

/* For inserting data in the first in list */
int dll_insert_first(Dlist **head, Dlist **tail, int data);

/* For inserting data in the last in list */
int dll_insert_last(Dlist **head, Dlist **tail, data_t data);

/* Printing the result sign */
void print_result(int sign, Dlist *head);

/* For Printing the list */
void print_list(Dlist *head);

/* Removing leading zeros */
void removing_leading_zeros(Dlist **head, Dlist **tail);

/* Comparing */
int compare(Dlist *head1, Dlist *head2);

/* To delete all the nodes from the list */
void dll_delete_list(Dlist **head, Dlist **tail);

/* Addition Function */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);

/* Subtraction Function */
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);

/* Function to check if the one of the Argument is zero */
int is_zero(Dlist *head, Dlist *tail);

/* Multiplication Function */
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);

/* Division Function */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);

/* Modulus Function */
int modulus(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);


#endif
