/**************************************************************************************************
	> File Name: BFS.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:图的深度优先搜索遍历
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
    struct ArcNode * next;

}ArcNode;

//定义顶点的数据结构
typedef struct  VertexNode
{
    DATATYPE data;
    int sign;
    ArcNode * head;
}VertexNode;

//定义整个邻阶表的数据结构
typedef struct
{
    VertexNode vertex[MAX];
    int vexnum;
    int arcnum;
}AdjList;

//定义队列的数据类型
typedef VertexNode QUData;

typedef struct
{
    QUData data[MAX];
    int head;
    int length;
}Sequeue;

//初始化队列
void Init(Sequeue *s)
{
    s->head=MAX-1;
    s->length=0;
}

//入队
int InsertQ(Sequeue *s,QUData d)
{
    if(s->length<MAX)
    {
        s->data[(s->head+1)%MAX]=d;
        s->length++;
        return 1;
    }
    return 0;
}

//出队
int Delete(Sequeue *s,QUData *d)
{
    if(s->length>0)
    {
        *d=s->data[(s->head+s->length-1)%MAX];
        s->length--;
        return 1;
    }
    return 0;
}



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
    p->adj=k;
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
        printf("%d : ",i);
        while(p!=NULL)
        {
            printf("%d    ",p->adj);
            p=p->next;
        }
        printf("\n");
    }
    printf("\n");
}
int Index(AdjList *a,DATATYPE d)
{
    int i;
    for(i=0;i<a->vexnum;i++)
    {
        if(a->vertex[i].data==d)
        {
            return i;
        }
    }
    return 0;
}
//打印出邻接矩阵
void BFS(AdjList *a,int i)
{
    Sequeue *s;
    QUData q;
    s=(Sequeue *)malloc(sizeof(Sequeue));
    Init(s);
    ArcNode *p;
    if(a->vertex[i].sign==0)
    {
        printf("%c ",a->vertex[i].data);
        a->vertex[i].sign=1;
    }
    p=a->vertex[i].head;
    while(p)
    {
        if(!a->vertex[p->adj].sign)
        {
            printf("%c ",a->vertex[p->adj].data);
            a->vertex[p->adj].sign=1;
            InsertQ(s,a->vertex[p->adj]);
        }
        //InsertQ(s,a->vertex[p->adj]);
        p=p->next;
    }
    
    while(s->length>0)
    {
        Delete(s,&q);
        BFS(a,Index(a,q.data));
    }
}
void BFS_2(AdjList *a,int i)
{
    Sequeue *s;
    QUData q;
    s=(Sequeue *)malloc(sizeof(Sequeue));
    Init(s);
    ArcNode *p;
    if(a->vertex[i].sign==0)
    {
        printf("%c ",a->vertex[i].data);
        a->vertex[i].sign=1;
    }
    InsertQ(s,a->vertex[i]);
    while(s->length>0)
    {
        Delete(s,&q);
        p=a->vertex[Index(a,q.data)].head;
        while(p)
        {
            if(!a->vertex[p->adj].sign)
            {
                printf("%c ",a->vertex[p->adj].data);
                a->vertex[p->adj].sign=1;
                InsertQ(s,a->vertex[p->adj]);
            }
            p=p->next;
        }
    }
}
void BFS_All(AdjList *a)
{
    int i;
    for(i=0;i<a->vexnum;i++)
    {
        if(!a->vertex[i].sign)
        {
            BFS(a,i);
        }
    }
}
int main()
{
    AdjList *a;
    a=(AdjList *)malloc(sizeof(AdjList));
    Created(a);
    Print(a);
    printf("\n\n");
    BFS_All(a);
}
