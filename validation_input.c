#include "apc.h"
#include<ctype.h>

/* Validation Part of the Input */
int validation_input(int argc, char *argv[])
{
    /* Validate operands only contains digits! */

    /* For checking Argument count */
    if(argc < 4)
    {
        printf("\033[1;31mError :\033[0m Insufficient Arguments!\n");
        printf("\033[1;31mUsage :\033[0m %s <Operand1> <Operator> <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Addition       :\033[0m %s <Operand1> + <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Subtraction    :\033[0m %s <Operand1> - <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Multiplication :\033[0m %s <Operand1> x <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Division       :\033[0m %s <Operand1> / <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Modulus        :\033[0m %s <Operand1> %% <Operand2>\n", argv[0]);

        return FAILURE;
    }
    else if(argc > 4)
    {
        printf("\033[1;31mError :\033[0m Too many Arguments!\n");
        printf("\033[1;31mUsage :\033[0m %s <Operand1> <Operator> <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Addition       :\033[0m %s <Operand1> + <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Subtraction    :\033[0m %s <Operand1> - <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Multiplication :\033[0m %s <Operand1> x <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Division       :\033[0m %s <Operand1> / <Operand2>\n", argv[0]);
        printf("\033[1;34mFor Modulus        :\033[0m %s <Operand1> %% <Operand2>\n", argv[0]);

        return FAILURE;
    }

    /* For Operand 1*/
	for (int i = 0; argv[1][i]; i++)
	{
        /* Sign allowed only as the first character */
		if(i == 0 && (argv[1][i]== '+' || argv[1][i] == '-'))
			continue;       // skip

		if(!isdigit(argv[1][i]))
		{
            printf("\033[1;31mError :\033[0m Argument1 <%s> must contain only digits!\n",argv[1]);
            return FAILURE;
        }
    }
    /* Must have at least one digit after sign */
    if((argv[1][0] == '+' || argv[1][0] == '-') && argv[1][1] == '\0')
    {
        printf("\033[1;31mError :\033[0m Argument1 <%s> must contain digits after sign!\n", argv[1]);
        return FAILURE;
    }

    /* For operator */
    if(!(argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == 'x' || argv[2][0] == '/' || argv[2][0] == '%'))
    {
        printf("\033[1;31mError :\033[0m  : Argument2 <%s> must contain only one operator (+, -, x, /, %%)!\n", argv[2]);
        return FAILURE;
    }
    /* After operator there must be nothing */
    if(argv[2][1] != '\0')
    {
        printf("\033[1;31mError :\033[0m Only operator must be present in Arg2 <%s>!\n", argv[2]);
        return FAILURE;
    }

    /* For Operand 2 */
    for (int i = 0; argv[3][i];i++)
    {
        /* Sign allowed only as the first character  */
        if(i == 0 && (argv[3][i] == '+' || argv[3][i] == '-'))
            continue;    // skip

        if(!isdigit(argv[3][i]))
        {
            printf("\033[1;31mError :\033[0m Argument3 <%s> must contain only digits!\n",argv[3]);
            return FAILURE;
        }
    }       
    /* Must have at least one digit after sign */
    if((argv[3][0] == '+' || argv[3][0] == '-') && argv[3][1] == '\0')
    {
        printf("\033[1;31mError :\033[0m Argument1 <%s> must contain digits after sign!\n", argv[3]);
        return FAILURE;
    }

    return SUCCESS;
}
