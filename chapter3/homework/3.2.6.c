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


int IsEmpty(LQueue *L)
{
    if(L->rear->next=L->rear)
    {
        return 0;
    }
    return 1;
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

int SetNull(LQueue *L)
{
    QNode *q;
    q=L->rear;
    L->rear->next=L->rear;
    while(q->next!=L->rear)
    {
        QNode *p;
        p=q;
        q=q->next;
        free(p);
    }
}


int Delete(LQueue *L,ElemType *e)
{
    QNode *p;
    if(IsEmpty(L))
    {
        printf("it is empty!\n");
        return 0;
    }
    p=L->rear->next;
    while(p->next!=L->rear)
    {
        p=p->next;   
    }
    *e=p->next->elem;
    L->rear=p;
    free(p->next);
    if(L->rear->next->next==L->rear)
    {
        SetNull(L);
    }
    return 1;
}
int main()
{
    
}
