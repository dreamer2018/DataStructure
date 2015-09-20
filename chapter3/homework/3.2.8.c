/*************************************************************************
	> File Name: 3.2.7.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Sun 20 Sep 2015 09:36:51 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType elem[MAXSIZE];
    int rear,front;
    int tag;   //tag=1 队列满 tag=-1 队列非空非满 tag=0 队列空
}QNode;

//判断队列是否为满
int IsFull(QNode *Q)
{
    if(Q->tag==1)
    {
        printf("The queue is full！\n");
        return 1;
    }
    return 0;
}

//判断队列是否为空
int IsEmpty(QNode *Q)
{
    if(Q->tag==0)
    {
        printf("queue is empty!\n");
        return 1;
    }
    return 0;
}

//初始化队列
int Init(QNode *Q)
{
    Q->rear=-1;
    Q->front=-1;
    Q->tag=-1;
}

//入队
int Insert(QNode *Q,ElemType e)
{
    if(IsFull(Q))
    {
        return 0;
    }
    Q->front++;
    Q->elem[Q->front]=e;
    if(Q->front==Q->rear)
    {
        Q->tag=1;
    }
    return 1;
}

//出队
int Delete(QNode *Q,ElemType *e)
{
    if(IsEmpty(Q))
    {
        printf("queue is empty!\n");
        return 0;
    }
    *e=Q->elem[Q->rear];
    Q->rear++;
    if(Q->rear==Q->front)
    {
        Q->tag=0;
    }
    return 1;
}
