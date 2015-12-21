/*************************************************************************
	> File Name: Sort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 2015 10:20:47 AM CST
 ************************************************************************/
#include<malloc.h>
#include<stdio.h>
#define DATATYPE int
#define MAX 100

//0号单元不使用
void InsertSort(DATATYPE *data,int n)
{
    int i,j;
    for(i=2;i<n;i++)
    {
        if(data[i]<data[i-1])
        {
            data[0]=data[i];
            for(j=i;data[0]<data[j-1];j--)
            {
                data[j]=data[j-1];
            }
            data[j]=data[0];
        }
    }
}
void BiInsertSort(DATATYPE *data,int n)
{
    int i,j;
    int low,high,mid;
    for(i=2;i<n;i++)
    {
        if(data[i]<data[i-1])
        {
            data[0]=data[i];
            low=1;
            high=i-1;      
            while(low<=high)
            {
                mid=(high+low)/2;
                if(mid < data[0])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            for(j=i-1;j>=low;j--)
            {
                data[j+1]=data[j];
            }
            data[low]=data[0];
        }
    }
}
void Print(DATATYPE *data ,int n)
{
    printf("\n");
    int i;
    for(i=1;i<n;i++)
    {
        printf("%d\t",data[i]);
    }
    printf("\n");
}
void main()
{
    int i;

    DATATYPE temp,data[MAX];
    for(i=1;i<MAX;i++)
    {
        scanf("%d",&temp);
        getchar();
        if(temp==0)
        {
            break;
        }
        data[i]=temp;
    }
    Print(data,i);
    InsertSort(data,i);
    Print(data,i);
}
