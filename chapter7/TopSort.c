/**************************************************************************************************
	> File Name: TopSort.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:
	> Created Time: Wed 09 Dec 2015 03:56:40 PM CST
 ************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//最大数据量
#define MAX 100

//定义数据类型
typedef  char DATATYPE;
//定义节点结构体
typedef struct ArcNode
{
    int adj;
    struct ArcNode * next;
}ArcNode;

//定义顶点数组结构体
typedef struct VertexNode
{
    DATATYPE data;
    ArcNode *head;
}VertexNode;

//定义整个邻阶表的数据结构
typedef struct
{
    VertexNode vertex[MAX];  //顶点数组
    int vexnum;     //顶点数
    int arcnum;     //弧数
}AdjList;
typedef struct
{
    int degree;  //入度值
    int sign;   //标记，0表示已被拓扑，1表示未被拓扑
}degay;
int Located(AdjList *a,DATATYPE d1)
{
    int i;
    for(i=0;i<a->vexnum;i++)
    {
        if(a->vertex[i].data==d1)
        {
            return i; 
        }
    }
    return -1;
}

//将输入的数据插入邻阶表中
void Insert(AdjList *a,int i,DATATYPE d1,DATATYPE d2)
{
    int j,k;
    ArcNode *p,*q;
    j=Located(a,d1);
    k=Located(a,d2);
    p=(ArcNode *)malloc(sizeof(ArcNode));
    p->adj=k+1;
    p->next=NULL;
    q=a->vertex[j].head;
    if(q==NULL)
    {
        a->vertex[j].head=p;
    }
    else if(q->next==NULL)
    {
        q->next=p;
    }
    else
    {
        while(q!=NULL && q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
}
//创建邻阶矩阵
void Created(AdjList *a)
{
    int i,j,k;
    DATATYPE d1,d2;
    ArcNode *p,*q;
    printf("请输入顶点数和关系数：");
    scanf("%d %d",&a->vexnum,&a->arcnum);
    getchar();
    printf("请输入%d个顶点：\n",a->vexnum);
    for(i=0;i<a->vexnum;i++)
    {
        printf("请输入No.%d个顶点：",i+1);
        scanf("%c",&a->vertex[i].data);
        getchar();
        a->vertex[i].head=NULL;
    }
    printf("请输入%d个关系：\n",a->arcnum);
    for(i=0;i<a->arcnum;i++)
    {
        printf("请输入No.%d个关系：",i+1);
        d1=getchar();
        d2=getchar();
        getchar();
        Insert(a,i,d1,d2);
        Insert(a,i,d2,d1);
    }
}
//打印出邻接矩阵
void Print(AdjList *a)
{
    int i;
    ArcNode *p,*q;
    printf("\n\n");
    for(i=0;i<a->vexnum;i++)
    {
        p=a->vertex[i].head;
        printf("%d : ",i+1);
        while(p!=NULL)
        {
            printf("%d    ",p->adj);
            p=p->next;
        }
        printf("\n");
    }
    printf("\n");
}
void InitArray(AdjList *a,degay *d)
{
    int i;
    for(i=0;i<a->vexnum;i++)
    {
        d[i].degree=0;
        d[i].sign=1;
    }
    ArcNode *p;
    for(i=0;i<a->vexnum ;i++)
    {
        p=a->vertex[i].head;
        while(p!=NULL)
        {
            d[p->adj].degree++;
            p=p->next;
        }
    }
}
#include<stdio.h>
int main()
{
}
