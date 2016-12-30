#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
#define is_number(chr) ((chr>='0')&&(chr<='9'))
void push(long int symbol);
long int pop();
void infix_to_postfix();
int priority(char symbol);
int isEmpty();
int white_space(char);
long int eval_post();
char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;
char operator_set[]="+-*/^()%";
int i=0;
int main()
{
    top=-1;
    printf("(makesure the arithmatic exp contains only single digit numbers)\n");
    printf("Enter infix Exp. : ");
    gets(infix);
    //checking for invalid infix arithmatic expression
    while(infix[i]!='\0')
    {
        if(!white_space(infix[i]) && !strchr(operator_set,infix[i]) && !is_number(infix[i]))
        {
            printf("\nInvalid arithmatic expression");
            return -1;
        }
        i++;
    }
    infix_to_postfix();
    printf("\n==>Postfix Exp.: %s\n",postfix);
    printf("\nThe postfix Exp. Evaluated to %d",eval_post());
    getch();
    return 0;
}
 
void infix_to_postfix()
{
    unsigned int i,p=0;
    char next;
    char symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(!white_space(symbol))
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!='(')
                    postfix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
                    postfix[p++]=pop();
                push(symbol);
                break;
            default: /*if an operand comes*/
                 postfix[p++]=symbol;
            }
        }
    }
    while(!isEmpty( ))
        postfix[p++]=pop();
    postfix[p]='\0'; /*End postfix with'\0' to make it a string*/
}
 
/*This function returns the priority of the operator*/
int priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default :
        return 0;
    }
}
 
void push(long int symbol)
{
    if(top>MAX)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top]=symbol;
}
 
long int pop()
{
    if( isEmpty() )
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return (stack[top--]);
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
 
int white_space(char symbol)
{
    if( symbol == BLANK || symbol == TAB )
        return 1;
    else
        return 0;
}
 
long int eval_post()
{
    long int a,b,temp,result;
    unsigned int i;
 
    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
            push(postfix[i]-'0');
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case '+':
                temp=b+a; break;
            case '-':
                temp=b-a;break;
            case '*':
                temp=b*a;break;
            case '/':
                temp=b/a;break;
            case '%':
                temp=b%a;break;
            case '^':
                temp=pow(b,a);
            }
            push(temp);
        }
    }
    result=pop();
    return result;
}
