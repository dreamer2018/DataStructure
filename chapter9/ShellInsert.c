/**************************************************************************************************
	> File Name: ShellInsert.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:
	> Created Time: 2015年12月21日 星期一 18时31分37秒
 ************************************************************************************************/

#include<stdio.h>
#include<malloc.h>
#define MAX 100
typedef int DATATYPE;
void ShellInsert(DATATYPE *data,int k,int n)
{
    int i,j;
    for(i=k+1;i<n;i++)
    {
        if(data[i]<data[i-k])
        {
            data[0]=data[i];
            for(j=i-k;j>0 && (data[0]<data[j]);j-=k)
            {
                data[j+k]=data[j];
            }
            data[j+k]=data[0];
        }
    }
}
void ShellSort(DATATYPE *data,int *k,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        ShellInsert(data,k[i],n);
    }
}
int main()
{

}
