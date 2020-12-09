/*
    Jans Johnson
    S3 cse Beta
    rollno:24
    U1903096
*/    

#include<stdio.h>
#include<stdlib.h>  
#include<ctype.h>     
#include<string.h>

#define SIZE 100


char stack[SIZE];
int top = -1;


void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}


int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}



int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')         
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               
	strcat(infix_exp,")");                  

	i=0;
	j=0;
	item=infix_exp[i];       

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
		else if(is_operator(item) == 1)        /* means symbol is operator */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);

			push(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* go to next symbol of infix expression */
	} 
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

}
int stackeval[20];
int topeval = -1;

void pusheval(int x)
{
    stackeval[++topeval] = x;
}

int popeval()
{
    return stackeval[topeval--];
}
void evaluate()
{
    int n1,n2,n3,num;
    int i=0;
    char postfix_exp[SIZE];
    printf("\nEnter Postfix expression : ");
    scanf("%s",postfix_exp);
    while(postfix_exp[i] != '\0')
    {
        if(isalpha(postfix_exp[i]))
        {
            printf("Enter value for %c:",postfix_exp[i]);
            scanf("%d",&num);
            pusheval(num);
        }
        else
        {
            n1 = popeval();
            n2 = popeval();
            switch(postfix_exp[i])
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            pusheval(n3);
        }
        i++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",postfix_exp,popeval());
}

int main()
{
	char infix[SIZE], postfix[SIZE];   
	int choice;
    printf("\n\n\n1. Convert infix to postfix\n2. Evaluate postfix expression\n\nYour choice:");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\nEnter Infix expression : ");
        gets(infix);

        InfixToPostfix(infix,postfix);                   /* call to convert */
        printf("Postfix Expression: ");
        puts(postfix);                     /* print postfix expression */
    }
    else if(choice==2)
    evaluate();
	return 0;
}
