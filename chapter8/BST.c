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

//创建二叉排序数的插入
void Insert(BST **b,DATATYPE tmp)
{
    if(*b==NULL)
    {
        *b=(BST *)malloc(sizeof(BST));
        (*b)->data=tmp;
        (*b)->LChild=NULL;
        (*b)->RChild=NULL;
    }
    else
    {
        if(tmp > (*b)->data)
        {
            Insert(&(*b)->RChild,tmp);
        }
        if(tmp < (*b)->data)
        {
            Insert(&(*b)->LChild,tmp);
        }
    }
}
//二叉排序树的创建
void Created(BST **b)
{
    DATATYPE tmp;
    while(1)
    {
        scanf("%d",&tmp);
        getchar();
        if(tmp==0)
        {
            break;
        }
        Insert(b,tmp);
    } 
}
void Print(BST *b)
{
    if(b!=NULL)
    {
        Print(b->LChild);
        printf("%d\t",b->data);
        Print(b->RChild);
    }
}
//非递归实现
BST *SerachBST(BST *b,DATATYPE d)
{
    BST *t;
    t=b;
    if(b==NULL)
    {
        return NULL;
    }
    while(t)
    {
        if(t->data==d)
        {
            return t;
        }
        else if(t->data < d)
        {
            t=t->RChild;
        }
        else
        {
            t=t->LChild;
        }
    }
}
//递归实现
BST *SerachBST2(BST *b,DATATYPE d)
{
    if(b==NULL)
    {
        return NULL;
    }
    if(b->data==d)
    {
        return b;
    }
    else if(b->data < d)
    {
        return SerachBST(b->RChild,d);
    }
    else
    {
        return SerachBST(b->LChild ,d);
    }
    
}
DATATYPE DeleteBST(BST *b,DATATYPE d)
{
    DATATYPE tmp=0;
    BST *t=NULL,*p,*q;
    p=b;
    while(p)
    {
        if(p->data==DATATYPE)
        {
            break;
        }
        t=p;
        if(p->key>k)
        {
            p=p->LChild;
        }
        else
        {
            p=p->RChild;
        }
    }
    //当找不到此节点时.直接结束
    if(p==NULL)
    {
        return tmp;
    }
    //当找到的是叶子节点
    if(p->RChild==NULL && p->LChild==NULL)
    {
        q=p;
        p=NULL;
        tmp=q->data;
        free(q);
        return tmp;
    }
    //当找到的是单枝节点
    if(p->RChild==NULL || p->LChild==NULL)
    {
        //右子数为空时
        if(p->RChild == NULL)
        {
            q=p;
            p=p->RChild;
            tmp=q->data;
            free(q);
        }
        //左子树为空时
        if(p->LChild == NULL)
        {
            q=p;
            p=p->LChild;
            tmp=q->data;
            free(q);
        }
    }
    //找到的是左右子树都有的节点
    
}
int main()
{
    BST *b=NULL,*p=NULL;
    Created(&b);
    p=SerachBST2(b,80);
    if(p!=NULL)
    {
        printf("%d\n",p->data);
    }
    else
    {
        printf("Not Found\n");
    }
}
