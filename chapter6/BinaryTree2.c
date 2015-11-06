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
    if(S->top<0)
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
int Push(StackNode *S,ElemType e)
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
int Pop(StackNode *S,ElemType *e)
{
    if(IsEmpty(S))
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
    ch=getchar();
    if(ch=='^')
    {
        return NULL;
    }
    BinaryTree *B;
    B=(BinaryTree *)malloc(sizeof(BinaryTree));
    B->data=ch;
    B->LChild=PreCreated();
    B->RChild=PreCreated();
    return B;
}
//先序遍历二叉树
void PreOrder(BinaryTree *B)
{
    if(B)
    {
        printf("%c\t",B->data);
        PreOrder(B->LChild);
        PreOrder(B->RChild);
    }
}
/*
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
    }while(S->top==0 && B->LChild);

}
*/
//中序创建二叉树
//后序创建二叉树
//输出栈中所有元素
void PrintStack(StackNode *S)
{
    int i;
    for(i=0;i<=S->top;i++)
    {
       printf("%c",S->elem[i]);
    }
    printf("\n");
}
//先序打印出从根到叶子结点的路径
void PrePrint(BinaryTree *root,StackNode *S)
{
    if(root)
    {
        ElemType e;
        Push(S,root->data);
        if(root->LChild==NULL && root->RChild==NULL)
        {
            Pop(S,&e);
            printf("\n%c:",e);
            PrintStack(S);
        }
        else
        {
            PrePrint(root->LChild,S);
            PrePrint(root->RChild,S);
            Pop(S,&e);
        }
    }
}

int main()
{
    StackNode *S;
    BinaryTree *B;
    S=(StackNode *)malloc(sizeof(StackNode));
    Init(S);
    B=PreCreated();
    PreOrder(B);
    PrePrint(B,S);
    printf("\n");
}
