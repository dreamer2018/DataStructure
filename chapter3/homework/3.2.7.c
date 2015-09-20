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
    int rear;
    int quelen;
}QNode;

int IsFull(QNode *Q)
{
    if(Q->quelen>=MAXSIZE)
    {
        printf("The queue is full！\n");
        return 1;
    }
    return 0;
}

//初始化队列
int Init(QNode *Q)
{
    Q->quelen=-1;
}

//入队
int Insert(QNode *Q,ElemType e)
{
    if(IsFull(Q))
    {
        return 0;
    }
    Q->quelen++;
    Q->elem[(Q->rear+Q->quelen)%MAXSIZE]=e; //队头算法：队尾加队列长度然后对队列长度求余
    return 1;
}

//出队
int Delete(QNode *Q,ElemType *e)
{
    if(Q->quelen==-1)
    {
        printf("queue is empty!\n");
        return 0;
    }
    *e=Q->elem[Q->rear];
    Q->rear=(Q->rear+1)%MAXSIZE;
    return 1;
}
