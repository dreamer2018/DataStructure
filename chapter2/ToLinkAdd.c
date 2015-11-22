/**************************************************************************************************
	> File Name: ToLinkAdd.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: 2015年11月22日 星期日 16时22分33秒
 ************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef int DataType;

typedef struct node
{
    DataType data;
    struct node *next;
}SNode,*SList;

//单链表的创建
SList Created()
{
    DataType temp;
    SList p,q,s;
    s=(SList )malloc(sizeof(SNode));
    scanf("%d",&temp);
    getchar();
    if(temp==0)
    {
        return NULL;
    }
    s->data=temp;
    s->next=NULL;
    q=s;
    while(1)
    {
        scanf("%d",&temp);
        getchar();
        if(temp==0)
        {
            break;
        }
        p=(SList)malloc(sizeof(SNode));
        p->data=temp;
        p->next=q->next;
        q->next=p;
        q=p;
    }
    
    return s;
}
//讲两条升序单链表合成一条
SList Merge(SList s1,SList s2)
{
    SList p,q,r,s; //定义中间变量
    
    p=s1; //p指向第一条链
    q=s2; //q指向第二条链
    
    //如果第一条链上的头小于第二条链上的头，则新的链表头指向第一条
    if(s1->data < s2->data)
    {
        s=s1;
        p=p->next;
    }
    else  //如果第二条链上的头小于第一条链上的头，则新的链表的头指向第二条
    {
        s=s2;
        q=q->next;
    }
    
    r=s;  //合成的新链表的头为s

    while(p!=NULL && q!=NULL)
    {
        //如果第一条链上的小于第二条链上的，则下一个结点指向第一个链上较小的结点
        if(p->data < q->data)
        {
            r->next=p;
            p=p->next;
        }
        else //如果第二条链上的小于或等于第一条链上的，则下一个结点指向第二个结点上较小的结点
        {
            r->next=q;
            q=q->next;
        }
        r=r->next;
    }
    //如果第一条链上的还没完，则将后续的加到新链表结尾
    if(p!=NULL)
    {
        r->next=p;
    }
    //如果第二条链上的还没完,则将后续的加到新链表结尾
    if(q!=NULL)
    {
        r->next=q;
    }
    //返回新的链表的结点
    return s;
}

//输出单链表里的内容
void PrintData(SList s)
{
    SList p;
    p=s;
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
void PrintData2(SList s)
{
    SList p;
    p=s;
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{
    SList s,s1,s2;
    s1=Created();
    s2=Created();
    PrintData(s1);
    PrintData(s2);
    s=Merge(s1,s2);
    printf("\t");
    PrintData(s);
}
