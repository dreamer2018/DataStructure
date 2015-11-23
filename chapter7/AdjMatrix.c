/**************************************************************************************************
	> File Name: AdjMatrix.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:无向图邻阶矩阵的创建，遍历
	> Created Time: 2015年11月23日 星期一 13时13分36秒
 ************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
//最大的数据量
#define MAX 20

#define INFINITY 0
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
    int i,j,add1,add2;
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
        scanf("%d %d",&add1,&add2);
        getchar();
        //一个就为有向图，两个就为无向图
        a->arcs[add1][add2]=1;
        a->arcs[add2][add1]=1;
    }
}

//打印
void PrintMatrix(AdjMatrix *a)
{
    int i,j;
    for(i=0;i<a->vexnum;i++)
    {
        for(j=0;j<a->vexnum;j++)
        {
            printf("%d\t",a->arcs[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    AdjMatrix *a;
    a=(AdjMatrix *)malloc(sizeof(AdjMatrix));
    Created(a);
    printf("\n\n");
    PrintMatrix(a);
}
