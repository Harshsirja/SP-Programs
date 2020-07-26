#include<stdio.h>
#include<string.h>
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
		case ')':return 1;
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
	char prefix[20],infix[20];
	int i=0,j=0;
	char c;
	printf("Enter the expression ");
	scanf("%s",infix);
	push('#');
	strrev(infix);
	//printf("%s",infix);
	while(infix[i]!=NULL)
	{
		if(isalnum(infix[i]))
		{
			prefix[j++]=infix[i];
		}
		else if(infix[i]==')')
		{
			push(infix[i]);
		}
		else if(infix[i]=='(')
		{
			while((c=pop())!=')')
			{

			prefix[j]=c;
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
				prefix[j]=pop();
				j++;
			}
			push(infix[i]);
		 }
		 i++;
	}
	while(s[top]!='#')
	{
		prefix[j]=pop();
		j++;
	}
	prefix[j]=NULL;
	strrev(prefix);
	printf("%s",prefix);
	return 0;
}
