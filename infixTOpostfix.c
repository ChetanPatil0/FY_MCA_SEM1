
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 20

struct stack
{
	int data[MAX];
	int top;
};

void init(struct stack *s)
{
	s->top=-1;
}

int empty(struct stack *s)
{
	if(s->top==-1)
		return(1);
	return(0);
}

void push(struct stack *s,int x)
{
	s->top++;
	s->data[s->top]=x;
}

int pop(struct stack *s)
{
	int x;
	x=s->data[s->top--];

	return(x);
}

int stktop(struct stack * s)
{
	return(s->data[s->top]);
}
int precedence(char ch)
{
   switch(ch)
   {
     case '(':return 0;
     case '+':
     case '-':return 1;
     case '*':
     case '/':
     case '%': return 2;
     case '$':
     case '^': return 3;
   }
   return 0;
}
void infix_to_postfix(char infix[30],char postfix[30])
{
struct stack s;
	char ch,ch1;
	int i,j=0;
     
	init(&s);
	for(i=0;infix[i]!='\0';i++)
	{
	       ch=infix[i];
	   switch(ch)
	 {
	   case '(':push(&s,ch);
	       break;
	   case '+':
	   case '-':
	   case '*':
	   case '/':
	   case '%':
	   case '$':
	   case '^':
	    if(empty(&s))
	push(&s,ch);
	else
	{
	 while(precedence(ch)<=precedence(stktop(&s)))
	  postfix[j++]=pop(&s);
	  push(&s,ch);
	}
	 break;
	 case ')':
		   while((ch1=pop(&s))!='(')
		    postfix[j++]=ch1;
		    break;
	 default:postfix[j++]=ch;
   }
}
	while(!empty(&s))
	       
		postfix[j++]=pop(&s);
postfix[j]='\0'; 
}

int main()
{
	char infix[30],postfix[30];

	printf("\nEnter an infix expression : ");
	scanf("%s",infix);
	infix_to_postfix(infix,postfix);
	printf("\nPostfix string is: %s  \n\n",postfix);

return 0;
   }
