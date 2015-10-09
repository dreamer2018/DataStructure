/*************************************************************************
	> File Name: Ghost_Language.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: Fri 09 Oct 2015 03:36:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAXSIZE 100

typedef char ElemType;

typedef struct Elem
{
	ElemType elem[MAXSIZE]; 
	int top; //栈顶
}StackNode;
//初始化栈
void Init(StackNode *S)
{
	S->top=-1;
}
//判空
int IsEmpty(StackNode *S)
{
	if(S->top<0)
	{
		printf("Stack is Empty !\n");
		return 1;
	}
	return 0;

}
//判满
int IsFull(StackNode *S)
{
	if(S->top>=MAXSIZE)
	{
		printf("Stack is Full !\n");
		return 1;
	}	
	return 0;
}
//入栈
int Push(StackNode *S,ElemType e)
{
	if(IsFull(S))
	{
		return 0;
	}
	S->top++;
	S->elem[S->top]=e;
	return 1;
}
//出栈
int Pop(StackNode *S,ElemType *e)
{
	if(IsEmpty(S))
	{
		return 0;
	}
	*e=S->elem[S->top];
	S->top--;
	return 1;
}
//字符解析

void Select(ElemType e)
{
	switch(e)
	{
		case 't':
			printf("天");
			break;
		case 'd':
			printf("地");
			break;
		case 's':
			printf("上");
			break;
		case 'a':
			printf("一只");
			break;
		case 'e':
			printf("鹅");
			break;
		case 'z':
			printf("追");
			break;
		case 'g':
			printf("赶");
			break;
		case 'x':
			printf("下");
			break;
		case 'n':
			printf("蛋");
			break;
		case 'h':
			printf("恨");
			break;
		default:
			printf(" ");
			
	}
}
int main()
{
    int i,j,k,sign=0,top;
	StackNode *S;
	char str[MAXSIZE];
	char A[4]={"sae"};
	char B[5]={"tAdA"};
	S=(StackNode *)malloc(sizeof(StackNode));
	Init(S);
	ElemType e;
	/*
	for(i=0;i<5;i++)
	{
		scanf("%c",&e);
		getchar();
		Push(S,e);
	}
	for(i=0;i<5;i++)
	{
		Pop(S,&e);
		printf("%c\n",e);
	}
	*/
	printf("Please Input :");
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='A')
		{
			for(j=0;j<3;j++)
			{
				Select(A[j]);
			}
		}
		else if(str[i]=='B')
		{
			for(j=0;j<4;j++)
			{
				if(B[j]=='A')
				{
					for(k=0;k<3;k++)
					{
						Select(A[k]);
					}
				}
				else
				{
					Select(B[j]);
				}
			}
		}
		else if(str[i]=='(')
		{
			sign=1;
		}
		else if(str[i]==')')
		{	
            if(S->top>0)
            {
                for(j=0;S->top>0;j++)
                {
                    Select(S->elem[0]);
                    Pop(S,&e);
                    Select(e);
                }
                Select(S->elem[0]);
            }
            else if(S->top==0)
            {
                Select(S->elem[0]);
            }
            sign=0;
		}
		else
		{
			if(sign)
			{
				Push(S,str[i]);
			}
			else
			{
                Select(str[i]);
			}
		}
	}
}
