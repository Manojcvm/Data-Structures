#include<stdio.h>
#define max 100
char stack[max];
int top=-1;

void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return stack[top--];
}
char peek()
{
    return stack[top];
}
int isoperand(char ch)
{

    return ((ch>='A'&&ch<='Z')|| (ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'));
}


int main()
{
    char infix[max],postfix[max];
    printf("Enter the expression:\n");
    scanf("%s",infix);
    printf("Infix expression: %s\n",infix);
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        char ch=infix[i];
        if(isoperand(ch))
        {
            postfix[j++]=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='?')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(top!=-1&&peek()!='(')
            {
              postfix[j++]=pop();
            }
            if(top!=-1&&peek()!='(')
            {
                pop();
            }
        }
           i++;
    }
    postfix[j]='\0';
    printf("Postfix Expression: %s\n",postfix);
    return 0;
}
