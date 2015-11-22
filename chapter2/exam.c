/**************************************************************************************************
	> File Name: exam.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: 2015年11月22日 星期日 14时01分33秒
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
    SList p,q,r,s,t;
    p=s1;
    q=s2;
    if(s1->data < s2->data)
    {
        s=s1;
        p=p->next;
    }
    else
    {
        s=s2;
        q=q->next;
    }
    r=s;
    while(p-> next!=NULL && q->next!=NULL)
    {
        if(p->data < q->data)
        {
            printf("test_1\n");
            t=p;
            p=p->next;
            //r=t;
        }
        else
        {
            printf("test_2\n");
            t=q;
            q=q->next;
            r=t;
        }
        r=r->next;
    }
    if(p->next!=NULL)
    {
        r=p;
        printf("t 1");
       // r=r->next;
       // q=q->next;
    }
    if(q->next!=NULL)
    {
        r=q;
        printf("t 2");
       // r=r->next;
       // q=q->next;
    }
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
    //printf("\n");
}
int main()
{
    SList s,s1,s2;
    s1=Created();
    s2=Created();
    PrintData(s1);
    PrintData(s2);
    s=Merge(s1,s2);
    PrintData2(s);
}
