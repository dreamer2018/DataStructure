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
void Created(BST **b,DATATYPE tmp)
{
    if(*b==NULL)
    {
        printf("test__1\n");
        *b=(BST *)malloc(sizeof(BST));
        (*b)->data=tmp;
        (*b)->LChild=NULL;
        (*b)->RChild=NULL;
    }
    else
    {
        printf("test__2\n");
        if(tmp > (*b)->data)
        {
            Created(&(*b)->RChild,tmp);
        }
        if(tmp < (*b)->data)
        {
            Created(&(*b)->LChild,tmp);
        }
    }
}
void Print(BST *b)
{
    if(b!=NULL)
    {
        printf("%d",b->data);
        Print(b->LChild);
        Print(b->RChild);
    }
}
int main()
{
    DATATYPE tmp;
    BST *b=NULL;
    while(1)
    {
        scanf("%d",&tmp);
        getchar();
        if(tmp==0)
        {
            break;
        }
        Created(&b,tmp);
    }
    Print(b);
}
