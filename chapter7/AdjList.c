/**************************************************************************************************
	> File Name: AdjList.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:邻阶表的创建，图的深度优先，广度优先遍历
	> Created Time: Wed 25 Nov 2015 03:22:55 PM CST
 ************************************************************************************************/

#include<stdio.h>
#include<malloc.h>

//最大数据量
#define MAX 100

//定义数据类型
typedef  char DATATYPE;
//定义节点结构体
typedef struct ArcNode
{
    int adj;
    int weight;
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
            
        }
    }
}
void Created(AdjList *a)
{
    int i;
    printf("请输入顶点数和关系数：");
    scanf("%d %d",a->vexnum,a->arcnum);
    getchar();
    printf("请输入%d个顶点：",a->vexnum);
    for(i=0;i<a->vexnum;i++)
    {
        scanf("%c",a->vertex[i].data);
        a->vertex[i].head=NULL;
    }
    getchar();
    printf("请输入%d个关系：",a->arcnum);
    for(i=0;i<a->arcnum;i++)
    {
        a->
    }
}
int main()
{
    AdjList *a;
    a=(AdjList *)malloc(sizeof(AdjList));
}
