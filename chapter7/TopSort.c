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
}AdjList;//定义队列的数据类型
typedef int QUData;

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
void PrintArray(int *d,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",d[i]);
    }
}
void InitArray(AdjList *a,int *d)
{
    int i;
    for(i=0;i<a->vexnum;i++)
    {
        d[i]=0;
    }
    ArcNode *p;
    for(i=0;i<a->vexnum ;i++)
    {
        p=a->vertex[i].head;
        while(p!=NULL)
        {
            //printf("test %d",p->adj);
            d[p->adj]++;
            p=p->next;
        }
    }
}
int TopSort(AdjList *a)
{
    int sign,i,count=0;
    Sequeue *s;
    s=(Sequeue *)malloc(sizeof(Sequeue));
    Init(s);
    int d[MAX];
    InitArray(a,d);
    PrintArray(d,a->vexnum);
    for(i=0;i<a->vexnum;i++)
    {
        if(d[i]==0)
        {
            InsertQ(s,i);
        }
    }
    while(s->length!=0)
    {
        int temp;
        ArcNode *p;
        Delete(s,&temp);

        printf("%c\t",a->vertex[temp].data);
        count++;
        p=a->vertex[temp].head;
        while(p!=NULL)
        {
            d[p->adj]--;
            if(d[p->adj]==0)
            {
                InsertQ(s,p->adj);
            }
            p=p->next;
        }
    }
    if(count< a->vexnum)
    {
        return 0;
    }
    return count;
}
int main()
{
    AdjList *a;
    a=(AdjList *)malloc(sizeof(AdjList));
    Created(a);
    Print(a);
    TopSort(a);
}
