/*************************************************************************
	> File Name: BinaryTree2.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: 2015年11月04日 星期三 15时49分13秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 100

typedef char ElemType;
typedef char DataType;
//定义栈结构体
typedef struct
{
    ElemType elem[MAXSIZE];
    int top;
}StackNode;

typedef struct binary
{
    DataType data;
    struct binary *LChild;
    struct binary *RChild;
}BinaryTree;

//初始化栈
void Init(StackNode *S)
{
    S->top=-1;
}

//判空
int IsEmpty(StackNode *S)
{
    if(S->top<=0)
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
//出栈
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

//入栈
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
//先序创建二叉树
BinaryTree *PreCreated()
{
    char ch;
    StackNode *S;
    BinaryTree *B;
    B=(BinaryTree *)malloc(sizeof(BinaryTree));
    S=(StackNode *)malloc(sizeof(StackNode));
    Init(S);
    do
    {
        ch=getchar();
        if(ch=='#')
        {

        }
    }while(S->top==0 && B->LChild)

    while(S)
}
//中序创建二叉树
//后序创建二叉树

int main()
{
    
}
