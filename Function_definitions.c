#include "apc.h"

/* Conversion of string to the list */
int string_to_list(char *str, Dlist **head, Dlist **tail)
{
    int i = 0, digit;
    if((i == 0) && (str[i] == '+' || str[i] == '-'))
    {
        i++;        // For skipping the first character if it is sign(-/+)
    }

    while(str[i] != '\0')
    {
        digit = str[i] - '0';     
        dll_insert_last(head, tail, digit);      // Function call inserting the digit into the linked list
        i++;      // Increment i for next character conversion
    }

    return SUCCESS;
}

/* Comparing Operands */
int compare(Dlist *head1, Dlist *head2)
{

    Dlist *temp1 = head1, *temp2 = head2;
    /* Removing zeros without changing originals */
    removing_leading_zeros(&head1, &temp1);
    removing_leading_zeros(&head2, &temp2);

    /* Count lengths */
    int len1 = 0, len2 = 0;

    Dlist *p = head1;
    while (p)
    {
        len1++;
        p = p->next;
    }

    p = head2;
    while (p)
    {
        len2++;
        p = p->next;
    }

    if(len1 > len2)
        return 1;
    
    if(len1 < len2)
        return -1;

    /* For comparing digit by digit */
    Dlist *a = head1;
    Dlist *b = head2;

    while(a && b)
    {
        if(a->data > b->data)
            return 1;
        
        if(a->data < b->data)
            return -1;

        a = a->next;
        b = b->next;
    }

    return 0;    // if Equal
}

/* Function definition of removing leading zeros */
void removing_leading_zeros(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
        return;

    Dlist *curr = *head;
    
    /* Removing nodes when they are zero */
    while(curr != NULL && curr->data == 0)
    {
        Dlist *temp = curr;
        curr = curr->next;
        free(temp);
    }

    /* All digits were zero -> make it as single zero node */
    if(curr == NULL)
    {
        Dlist *zero = malloc(sizeof(Dlist));
        zero->data = 0;
        zero->prev = zero->next = NULL;
        *head = *tail = zero;
        return;
    }

    /* Fix new head */
    curr->prev = NULL;
    *head = curr;

    /* Fix tail */
    Dlist *t = curr;
    while(t->next)
        t = t->next;

    *tail = t;
}

/* Insert First Function */
int dll_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if(*head)
        (*head)->prev = new;
    else
        *tail = new;

    *head = new;

    return SUCCESS;
}

/* Insert last Function */
int dll_insert_last(Dlist **head, Dlist **tail, data_t data)
{
    /* Dynamically allocating the memory for the node */
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));  
    /*Checking memory is allocated or not */
    if(!new)     
        return FAILURE;

    new->data = data;        
    new->next = NULL;
    new->prev = *tail;

    if(*tail)
        (*tail)->next = new;       // After the first node to add 
    else
        *head = new;              // To add as the first node

    *tail = new;                // Update the tail after adding new node

    return SUCCESS;
}
/* To free all the nodes of the list */
void dll_delete_list(Dlist **head, Dlist **tail)
{
    while(*head)
    {
        Dlist *temp = *head;     // Store the (*head) into the temporary pointer
        *head = (*head)->next;      // Traverse head to next node 
        free(temp);         // And free the temp pointing at the current 
    }
    *tail = NULL;
}
/* Checking if the any list head is containing zero or not */
int is_zero(Dlist *head, Dlist *tail)
{
    /* If list is empty treat as 0 */
    if(!head)
    return 0;

    Dlist *temp = head;
    while(temp)
    {
        if(temp->data != 0)
        return 0;      // Not a zero number
        
        temp = temp->next;
    }
    /* All digits were zero */
    return 1;  
}

/* For printing the result with sign */
void print_result(int sign, Dlist *head)
{
    printf("Result   = ");
    if (sign == -1)
        printf("-");
    // Function call
    print_list(head);   // already prints a newline
}

/* For printing the result list */
void print_list(Dlist *head)
{
    while(head)
    {
        printf("%d", head->data);
        head = head->next;   // Traversing the node to the next
    }
    printf("\n");
}