/*************************************************************************
	> File Name: Polyomial.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Wed 23 Sep 2015 05:30:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100


typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int top;
}StackNode;

//初始化
void Init(StackNode *S)
{
    S->top=-1;
}

//判空
int IsEmpty(StackNode *S)
{
    if(S->top==-1)
    {
        return 1;
    }
    return 0;
}

//判满
int IsFull(StackNode *S)
{
    if(S->top>=MAXSIZE)
    {
        return 1;
    }
    return 0;
}

//入栈
int Insert(StackNode *S,ElemType e)
{
    if(IsFull(S))
    {
        printf("Stack is full!\n");
        return 0;
    }
    S->top++;
    S->elem[S->top]=e;
    return 1;
}

//出栈
int Delete(StackNode *S,ElemType *e)
{
    if(IsEmpty(S))
    {
        printf("Stack is Empty!\n");
        return 0;
    }
    *e=S->elem[S->top];
    S->top--;
    return 1;
}

int main()
{
    int i,j,k=-1,h=-1,len;
    char str[102],ch;
    int num[100][100];
    ElemType e;
    StackNode *S1,*S2;
    S1=(StackNode *)malloc(sizeof(StackNode));  //括号栈
    S2=(StackNode *)malloc(sizeof(StackNode));  //数值栈
    Init(S1);
    Init(S2);
    printf("Please Input:");
    str[0]='#';
    for(i=1;;i++)
    {
	ch=getchar();
  	if(ch=='\n')
	{
	    str[i]='#';
	    str[i+1]='\0';
	    break;
	}
	str[i]=ch;
    }
    printf("%s",str);
    for(j=1;j<i;j++)
    {
	if(j>30 && j<39)
	{
		k++;
		h=-1;
		while(1)
		{
			if(str[j]>39||str[j]<30)
			{
				j--;
				break;
			}
			h++;	
		}	num[k][h]=str[j];
	}
    }
    
}
