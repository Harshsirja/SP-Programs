#include<stdio.h>
#include<conio.h>
#define size 5
int top=-1,s[size];
void push(char a)
{
	top++;
	s[top]=a;
}
char pop()
{
	char c;
	c=s[top];
	top--;
	return c;
}
int prece(char b)
{
	switch(b)
	{
		case '#':return 0;
		case '(':return 1;
		case '+':
		case '-':return 2;
		case '*':
		case '/':return 3;
		case '^':return 4;
	}
	return 0;
}
int main()
{
	char postfix[20],infix[20];
	int i=0,j=0;
	char c;
	printf("Enter the expression ");
	scanf("%s",infix);
	push('#');
	while(infix[i]!=NULL)
	{
		if(isalnum(infix[i]))
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='(')
		{
			push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((c=pop())!='(')
			{

			postfix[j]=c;
			j++;
		 }
		}
		else if(infix[i]=='^')
		{
		     push(infix[i]);
		}
		else
		{
			while(prece(s[top])>=prece(infix[i]))
			{
				postfix[j]=pop();
				j++;
			}
			push(infix[i]);
		 }
		 i++;
	}
	while(s[top]!='#')
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]=NULL;
	printf("%s",postfix);
	return 0;
}
