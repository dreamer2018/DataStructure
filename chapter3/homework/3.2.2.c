/*************************************************************************
	> File Name: Stack_Test.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Tue 15 Sep 2015 09:27:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAXSIZE 1000
typedef char ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int top;
}StackNode;

void Init(StackNode *S)
{
    S->top=-1;
}

int Push(StackNode *S,ElemType e)
{
    if(S->top>=MAXSIZE-1)
    {
        printf("Stack is full!\n");
        return 0;
    }
    S->top++;
    S->elem[S->top]=e;
    return 1;
}

int Pop(StackNode *S,ElemType *e)
{
    if(S->top<0)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    *e=S->elem[S->top];
    S->top--;
}

int Judge(ElemType *elem,int n)
{    
    int i;
    ElemType *a;
    a=(ElemType *)malloc(n*sizeof(ElemType));
    StackNode *S;
    S=(StackNode *)malloc(sizeof(StackNode));
    Init(S);
    for(i=0;i<n;i++)
    {   
        Push(S,elem[i]);
    }
    for(i=0;i<n;i++)
    {
        Pop(S,&a[i]);
    }
    if(!strncmp(elem,a,n))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int i=-1;
    ElemType e,elem[MAXSIZE];
    while(1)
    {
        i++;
        scanf("%c",&e);
        if( e == '\n' || i>=MAXSIZE)
        {
            break;   
        }
        elem[i]=e;
    }
    if(Judge(elem,i)) //Judge是回文数判断函数，是返回1不是返回0
    {
        printf("是回文！\n");   
    }
    else
    {
        printf("不是回文！\n");
    }
}
