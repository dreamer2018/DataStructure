/**************************************************************************************************
	> File Name: BST.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Function:
	> Created Time: Tue 15 Dec 2015 05:50:48 PM CST
 ************************************************************************************************/

#include<stdio.h>
#include<malloc.h>
#define DATATYPE int

typedef struct BinSerach 
{
    DATATYPE data;
    struct BinSerach *LChild;
    struct BinSerach *RChild;
}BST;

//创建二叉排序数
void Created(BST *b,DATATYPE tmp)
{
    if(b=NULL)
    {
        b=(BST *)malloc(sizeof(BST));
        b->data=tmp;
        b->LChild=NULL;
        b->RChild=NULL;
    }
    else
    {
        if(tmp>)
        {
            Created(b->LChild);
            Created(b->RChild);
        }
    }
}
int main()
{
}
