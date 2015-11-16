/**************************************************************************************************
	> File Name: Forest.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: 2015年11月16日 星期一 12时29分40秒
 ************************************************************************************************/

#include<stdio.h>
#include<malloc.h>

//定义森林的数据类型
#define DATATYPE char

//定义森林的数据结构
typedef struct forest
{
    DATATYPE data;
    struct forest *FirstChild;
    struct forest *NextSibling;
}ForestNode;

//先序创建森林
void Created(ForestNode **f)
{
    DATATYPE ch;
    ch=getchar();
    if(ch=='^')
    {
        *f=NULL;
    }
    else
    {
        *f=(ForestNode *)malloc(sizeof(ForestNode));
        (*f)->data=ch;
        Created(&((*f)->FirstChild));
        Created(&((*f)->NextSibling));
    }
}

//先根遍历二叉树
void RootFirst(ForestNode *f)
{
    ForestNode *t;
    t=f;
    if(t!=NULL)
    {
        printf("%c\t",t->data);
        t=t->FirstChild;
        while(t)
        {
            RootFirst(t);
            t=t->NextSibling;
        }
    }
}
//后根遍历
void RootFinal(ForestNode *f)
{
    if(f)
    {
        RootFinal(f->FirstChild);
        printf("%c\t",f->data);
        RootFinal(f->NextSibling);
    }
}
//求叶子节点个数
int leaf=0;
void Count_Leaf1(ForestNode *f)
{
    if(f)
    {
        if(f->FirstChild==NULL)
        {
            leaf++;
        }
        Count_Leaf1(f->FirstChild);
        Count_Leaf1(f->NextSibling);
    }
}
//求叶子节点个数方法2
int Count_Leaf2(ForestNode *f)
{
    int h1=0,h2=0,h=0;
    if(f)
    {
        if(f->FirstChild==NULL)
        {
            h++;
        }
        h1=Count_Leaf2(f->FirstChild);
        h2=Count_Leaf2(f->NextSibling);
        return h1+h2+h;
    }
    return 0;
}
//计算森林的高度
int high=0;

void Count_High1(ForestNode *f,int h)
{
    if(f)
    {
        if(high<h)
        {
            high=h;
        }
        Count_High1(f->FirstChild,h+1);
        Count_High1(f->NextSibling,h);
    }
}
//计算森林的高度方法二
int Count_High2(ForestNode *f)
{
    if(f)
    {
        int n=Count_High2(f->FirstChild);
        int m=Count_High2(f->NextSibling);
        return (m>n ? m:n+1);
    }
    return 0;
}

int main()
{
    ForestNode *f;
    Created(&f);
    RootFirst(f);
    printf("\n");
    RootFinal(f);
    printf("\n");
    high=Count_High2(f);
    printf("%d\t\n",high);
    leaf=Count_Leaf2(f);
    printf("%d\t\n",leaf);
}
