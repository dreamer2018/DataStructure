/*************************************************************************
	> File Name: 3.2.6.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Wed 16 Sep 2015 04:36:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct Queue
{
    ElemType elem;
    struct Queue *next;
}QNode;
typedef struct
{
    QNode *rear;
}LQueue;

LQueue *Init(QNode *Q,LQueue *L)
{ 
    QNode *p;
    LQueue *q;
    p=(QNode *)malloc(sizeof(QNode));
    q=(LQueue *)malloc(sizeof(LQueue));
    p->next=p;
    q->rear=p;
    return q;
}

int Insert(LQueue *L,ElemType e)
{
    QNode *s;
    s=(QNode *)malloc(sizeof(QNode));
    if(s==NULL)
    {
        printf("pos is error!\n");
        return 0;
    }
    L->rear->elem=e;
    s->next=L->rear->next;
    L->rear->next=s;
    return 1;
}

int Delete(QNode *h)
{
    
}

int IsEmpty()
{
    
}

int main()
{}
