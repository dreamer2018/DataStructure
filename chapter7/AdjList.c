/**************************************************************************************************
	> File Name: AdjList.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:邻阶表的创建，图的深度优先，广度优先遍历
	> Created Time: Wed 25 Nov 2015 03:22:55 PM CST
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
void Created(AdjList *a)
{
    int i,j,k;
    DATATYPE d1,d2;
    ArcNode *p,*q;
    printf("请输入顶点数和关系数：");
    scanf("%d %d",a->vexnum,a->arcnum);
    getchar();
    printf("请输入%d个顶点：",a->vexnum);
    for(i=0;i<a->vexnum;i++)
    {
        scanf("%c",a->vertex[i].data);
        getchar();
        a->vertex[i].head=NULL;
    }
    printf("请输入%d个关系：",a->arcnum);
    for(i=0;i<a->arcnum;i++)
    {
        d1=getchar();
        d2=getchar();
        j=Located(a,d1);
        k=Located(a,d2);
        if(j<0|| k<0)
        {
            printf("not this %c",d1);
            exit(0);
        }
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adj=k;
        p->next=NULL;
        q=a->vertex[j].head;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
}
int main()
{
    AdjList *a;
    a=(AdjList *)malloc(sizeof(AdjList));
}
