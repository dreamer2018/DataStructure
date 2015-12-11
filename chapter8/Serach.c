/*************************************************************************
    > File Name: 1.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Fri 11 Dec 2015 04:59:11 PM CST
 ************************************************************************/

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
		if(list[i]==k)
			return i;
	}
	return 0;
}
int InsertSort2(List *list,DATATYPE k,int n)
{	
	int i=n-1;
	list[0]=k;
	while(list[i]!=k)
	{
		i--;
	}
	return i;
}
