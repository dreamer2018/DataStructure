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
BST *DeleteBST(BST *b,DATATYPE d)
{
    BST *p,*f,*s,*q;
    p=b;
    f=NULL;

    //找出要删除的节点
    while(p)
    {
        if(p->data==d)
        {
            break;
        }
        f=p; //f记录节点的父节点
        if(p->data > d)
        {
            p=p->LChild;
        }
        else
        {
            p=p->RChild;
        }
    }
    //如果要删除的节点不存在，则直接返回
    if(p==NULL)
    {
        return b;
    }
    //单枝节点
    if(p->LChild == NULL)
    {
        //f 等于NULL，则表示是要删的是根结点
        if(f==NULL)
        {
            // 要删的是根结点，且左子树为空
            b=p->RChild;
        }
        else if (f->LChild == p)
        {

            f->LChild = p->RChild;
        }
        else
        {
            f->LChild=p->RChild;
        }
        free(p);
    }
    else
    {
        q=p;
        s=p->LChild;
        while(s->RChild)
        {
            q=s;
            s=s->RChild;
        }
        if(q=p)
        {
            q->LChild=s->LChild;
        }
        else
        {
            q->RChild=s->LChild;
        }
        p->data=s->data;
        free(s);
    }
    return b;
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
