/**************************************************************************************************
	> File Name: BFS.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:图的深度优先搜索
	> Created Time: Wed 25 Nov 2015 07:15:22 PM CST
 ************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//定义最大数据量
#define MAX 100

//定义数据类型
typedef char DATATYPE ;

//定义节点数据结构
typedef struct ArcNode
{
    int adj;
    int sign;
    struct ArcNode * next;

}ArcNode;

//定义顶点的数据结构
typedef struct  VertexNode
{
    DATATYPE data;
    ArcNode * head;
}VertexNode;

//定义整个邻阶表的数据结构
typedef struct
{
    VertexNode vertex[MAX];
    int vexnum;
    int arcnum;
}AdjList;
//定位出d1位于哪个位置
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
    p->sign=0;
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

//创建邻阶表
void Created(AdjList *a)
{
    int i,j,k;
    DATATYPE d1,d2;
    printf("请输入节点数和关系数：");
    scanf("%d %d",&a->vexnum,&a->arcnum);
    getchar();
    for(i=0;i<a->vexnum;i++)
    {
        printf("请输入No.%d个节点：",i+1);
        scanf("%c",&a->vertex[i].data);
        getchar();
        a->vertex[i].head=NULL;
    }
    for(i=0;i<a->arcnum;i++)
    {
        printf("请输入No.%d个关系：",i+1);
        d1=getchar();
        d2=getchar();
        getchar();
        Insert(a,i,d1,d2);
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
int main()
{
    AdjList *a;
    a=(AdjList *)malloc(sizeof(AdjList));
    Created(a);
    Print(a);
}
