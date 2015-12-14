/**************************************************************************************************
	> File Name: Serach.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:数据的查询算法，分别有顺序查找，折半查找
	> Created Time: Mon 14 Dec 2015 09:09:30 AM CST
 ************************************************************************************************/

#include<stdio.h>

#define DATATYPE int 
typedef struct
{
	DATATYPE data;
}List;
//零号单元不存值
int InsertSort(List *list,DATATYPE k,int n)
{
	int i;
	for(i=n-1;i>=1;i--)
	{
		if(list[i].data==k)
			return i;
	}
	return 0;
}
//加监视哨
int InsertSort2(List *list,DATATYPE k,int n)
{	
	int i=n-1;
	list[0].data=k;
	while(list[i].data!=k)
	{
		i--;
	}
	return i;
}
//折半查找(非递归)
int BinSerach(List *list,DATATYPE k,int n) 
{
    int high,low,mid,i=0;
    high=n-1;
    low=1;
    mid=(high+low)/2;
    while(high>=low)
    {
        if(k<list[mid].data)
        {
            high=mid-1;
        }
        else if(k>list[mid].data)
        {
            low=mid+1;
        }
        else
        {
            return mid;
        }
        mid=(high+low)/2;
    }
    return 0;
}
//折半查找（递归实现）
int BinSerach2(List *list,DATATYPE k,int b,int e) // b 为数组下限，e为数组上限
{
    int high,low,mid;
    high=e;
    low=b;
    mid=(high+low)/2;
    if(high>=low)
    {
        if(list[mid].data==k)
        {
            return mid;
        }
        else if(list[mid].data>k)
        {
            high=mid-1;
           return BinSerach2(list,k,low,high);
        }
        else
        {
            low=mid+1;
            return BinSerach2(list,k,low,high);
        }
    }
    return 0;
}
int main()
{
    int i;
    List list[10];
    for(i=1;i<10;i++)
    {
        list[i].data=i;   
    }
    printf("%d \t\n",BinSerach2(list,7,1,9));
}
