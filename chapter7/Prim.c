/**************************************************************************************************
	> File Name: Prim.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:
	> Created Time: Mon 07 Dec 2015 09:29:38 AM CST
 ************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//最大的数据量
#define MAX 20

//定义正无穷
#define INFINITY 65535

//数据的类型
typedef char DataType;

//邻阶矩阵的结构体
typedef struct
{
    //顶点在数组中的位置信息
    int arcs[MAX][MAX];
    //顶点储存的信息
    DataType data[MAX];
    //顶点个数
    int vexnum;
    //边的个数
    int arcnum;

}AdjMatrix;

//临阶矩阵的创建
void Created(AdjMatrix *a)
{
    int i,j,weight;
    int add1,add2;
    printf("请输入顶点数和边数：");
    scanf("%d %d",&a->vexnum,&a->arcnum);
    getchar();
    for(i=0;i<a->vexnum;i++)
    {
        for(j=0;j<a->vexnum;j++)
        {
            a->arcs[i][j]=INFINITY;
        }
    }
    printf("请输入%d个顶点:\n",a->vexnum);
    for(i=0;i<a->vexnum;i++)
    {
        printf("No.%d个顶点：",i+1);
        scanf("%c",&a->data[i]);
        getchar();
    }
    printf("請輸入%d條邊：\n",a->arcnum);
    for(i=0;i<a->arcnum;i++)
    {
        printf("No.%d條邊：",i+1);
        scanf("%d %d %d",&add1,&add2,&weight);
        getchar();
        //scanf("%d",&weight);
        //getchar();
        //一个就为有向网，两个就为无向网
        a->arcs[add1][add2]=weight;
        a->arcs[add2][add1]=weight;
    }
}

//打印
void PrintMatrix(AdjMatrix *a)
{
    int i,j;
    printf("\n");
    for(i=0;i<a->vexnum;i++)
    {
        for(j=0;j<a->vexnum;j++)
        {
            if(a->arcs[i][j]!=INFINITY)
            {
                printf("%d\t",a->arcs[i][j]);
            }   
        }
        printf("\n");
    }
}

//Prim算法

void Prim(AdjMatrix *a,int start)
{
    struct 
    {
        int adjvex;
        int lowcost;
    }closedge[MAX];

    int i,j,m,min;
    for(i=0;i<a->vexnum;i++)
    {
        closedge[i].adjvex=start;
        closedge[i].lowcost=a->arcs[start][i];
    }
    closedge[start].lowcost=0;
    
    //找出权值最小的边
    for(j=0;j<a->vexnum-1;j++)
    {
        min=INFINITY;
        //printf("%d",a->vexnum);
        for(i=0;i<a->vexnum;i++)
        {
            //printf("++++++++%d\n",closedge[i].adjvex);
            if(closedge[i].lowcost!=0 && closedge[i].lowcost<min )
            {
                m=i;
              //  printf("%d\n",m);
                min=closedge[i].lowcost;
            }
        }
        closedge[m].lowcost=0;
        
        //遍历矩阵m列的数据，发现小于的，就更新
        for(i=0;i<a->vexnum;i++)
        {
            //int j=0;
            if(i!=m && a->arcs[m][i] < closedge[i].lowcost)
            {
                printf("test %d %d \n",m,i);
                //printf("%c %c\n",a->data[m],a->data[i]);
                closedge[i].adjvex=m;
                closedge[i].lowcost=a->arcs[m][i];
            }
        }
    }
}
int main()
{
    AdjMatrix *a;
    a=(AdjMatrix *)malloc(sizeof(AdjMatrix));
    Created(a);
    PrintMatrix(a);
    Prim(a,9);
    //PrintMatrix(a);
}
