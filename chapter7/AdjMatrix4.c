#include <stdio.h>
#define MAXSIZE 20
#define INFINITY 32767

typedef int Vextype;
typedef struct 
{
	int arcs[MAXSIZE][MAXSIZE];
	Vextype vex[MAXSIZE];
	int vexnum;
	int arcsnum;
 } AdjMatrix;

/*
//通过输入节点，返回其在数组中的下标
int Index(Vextype *a,Vextype b,int n)  //n为数组的实际存储数据的长度，即无向图节点个数
{
    int i;
    for(i=0;i<=n;i++)
    {
        if(a[i]==b)
        {
            return i;
        }
    }
    return 0;
}
*/
//用邻接矩阵创建无向网
void Creat(AdjMatrix *G)
{
 	int i,j,k,weight,vex1,vex2;
 	printf("请输入邻接矩阵的结点数和边数：");
 	scanf("%d%d",&G->vexnum,&G->arcsnum);
 	printf("初始化矩阵");
 	for(i=1;i<=G->vexnum;i++)
    {
	 	for(j=1;j<=G->vexnum;j++)
        {
	    	G->arcs[i][j]=INFINITY; 
        }
    }
	printf("请输入%d个结点请\n",G->vexnum);
	for(i=1;i<=G->vexnum;i++)
	{
        printf("please input No.%d vex:",i);
		scanf("%d",&G->vex[i]);
	}
	printf("请输入%d条边\n",G->arcsnum);
	for(k=1;k<=G->arcsnum;k++)
	{

		printf("please input No.%d arcs\t结点vex1,vex2:",k);
		scanf("%d%d",&vex1,&vex2);
		printf("请输入权值：");
		scanf("%d",&weight);
		//这里应该加一个定位函数，通过节点定位出数组下标
        //G->arcs[Index(G->vex,vex1,G->vexnum)][Index(G->vex,vex2,G->vexnum)]=weight;
        //G->arcs[Index(G->vex,vex2,G->vexnum)][Index(G->vex,vex1,G->vexnum)]=weight;
        //或者就直接输入的是节点对应的下标的关系
        G->arcs[vex1][vex2]=weight;
        G->arcs[vex2][vex1]=weight;
	}
}

int main(void)
{
  	AdjMatrix *G;
  	int i,j;
	Creat(G);
	printf("\n");
    for(i=1;i<=G->vexnum;i++)
	{
        //printf("%2d:\t",G->vex[i]);
		for(j=1;j<=G->vexnum;j++)
        {
            //这里应该要if判断应该是不等于正无穷,还有输出应该是%d,not &d
			if(G->arcs[i][j]!=INFINITY)
				printf("%d\t",G->arcs[i][j]);
        }
		printf("\n");
	}
	for(i=1;i<=G->vexnum;i++)
		printf("%d   ",G->vex[i]);
    printf("\n");
	return 0;
}
