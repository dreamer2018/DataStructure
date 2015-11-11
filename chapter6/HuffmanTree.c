/*************************************************************************
	> File Name: HuffmanTree.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: 2015年11月11日 星期三 19时11分43秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

#define N 4
#ifdef N
#define H 2*N-1
#endif

typedef struct
{
    int Weight;
    int Parent;
    int LChild;
    int RChild;
}HufNode;

void InitHuffTree(int *W,HufNode *h)
{
    int i;
    for(i=0;i<N;i++)
    {
        h[i].Weight=W[i];
        h[i].Parent=0;
        h[i].LChild=0;
        h[i].RChild=0;
    }
    for(;i<H;i++)
    {
        h[i].Weight=0;
        h[i].Parent=0;
        h[i].LChild=0;
        h[i].RChild=0;   
    }
}
void FindMin(int n,HufNode *h,int *n1,int *n2)
{
    int i,j;
    HufNode h1,h2;
    for(i=0;i<n;i++)
    {
        if(h[i].Parent==0)
        {
            h1=h2=h[i];
            *n1=*n2=i;
           // printf("%d %d\n",*n1,*n2);
        }
    }
    printf("%d %d\n",*n1,*n2);
    j=i+1;
    for(i=j;i<n;i++)
    {
        if(h[i].Parent==0 && h[i].Weight< h1.Weight)
        {
            h1=h[i];
            *n1=i;
        }
        if(h[i].Parent==0 && h[i].Weight>h2.Weight)
        {
            printf("test\n");
            h2=h[i];
            *n2=i;
        }
    }
    printf("%d %d\n",*n1,*n2);
    for(i=j;i<n;i++)
    {
        if(h[i].Parent==0 && h[i].Weight<h2.Weight && *n1!=i)
        {
            h2=h[i];
            *n2=i;
            printf("test\n");
        }
    }
}
void CreateHuffTree(HufNode *h)
{
    int i;
    int  n1,n2;
    for(i=N;i<H;i++)
    {
        FindMin(i,h,&n1,&n2);
        printf("%d %d\n",n1,n2);
        h[i].Weight=h[n1].Weight+h[n2].Weight;
        h[i].LChild=n1;
        h[i].RChild=n2;
        h[n1].Parent=h[n2].Parent=i;
    }
}
void PrintHufTree(HufNode *h)
{
    int i;
    for(i=0;i<H;i++)
    {
        printf("%d %d %d %d %d\n",i,h[i].Weight,h[i].Parent,h[i].LChild,h[i].RChild);
    }
}

int main()
{
    HufNode h[H];
    int w[N]={1,3,6,9};
    InitHuffTree(w,h);
    CreateHuffTree(h);
    PrintHufTree(h);
}
