/*************************************************************************
	> File Name: 1.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Thu 24 Sep 2015 09:06:08 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct polyomial
{
    int coef;   //指数
    int index;  //系数
    struct polyomial *next;
}PolyNode;
int Insert_Tail(PolyNode *head,PolyNode *p)
{
    PolyNode *q;
    q=head;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
}

void Plus(PolyNode*head1, PolyNode *head2)
{
    PolyNode *p,*q,*r;
    q=head2;
    while(q->next!=NULL)
    {
        p=head1;
        q=q->next;
        while(1)
        {
            p=p->next;
           
            if(q->coef==p->coef)
            {
                p->index+=q->index;
                break;
            }
            
            if(p->next==NULL)
            {
                r=(PolyNode *)malloc(sizeof(PolyNode));
                r->coef=q->coef;
                r->index=q->index;
                r->next=p->next;
                p->next=r;
                break;
            }
        }
    }
}

void Reduce(PolyNode *head1, PolyNode *head2)
{
    PolyNode *p,*q,*r;
    q=head2;
    while(q->next!=NULL)
    {
        p=head1;
        q=q->next;
        while(1)
        {
            p=p->next;
            
            if(q->coef==p->coef)
            {
                p->index-=q->index;
                break;
            }
            
            if(p->next==NULL)
            {
                r=(PolyNode *)malloc(sizeof(PolyNode));
                r->coef=q->coef;
                r->index=-q->index;
                r->next=q->next;
                p->next=r;
                break;
            }
        }
    }
}

PolyNode *Multiply(PolyNode *head1,PolyNode *head2)
{
    PolyNode *p,*q,*r,*s,*head;
    head=(PolyNode *)malloc(sizeof(PolyNode));
    head->next=NULL;
    q=head2;
    while(q->next!=NULL)
    {
        p=head1;
        q=q->next;
        while(p->next!=NULL)
        {
            p=p->next;
            int sign=0;
            int coef=p->coef+q->coef;
            int index=p->index*q->index;
            s=head;
            while(s->next!=NULL)
            {
                s=s->next;
                if(s->coef==coef)
                {
                    s->index+=index;
                    sign=1;
                    break;
                }
            }
            if(sign==0)
            {
                r=(PolyNode *)malloc(sizeof(PolyNode));
                r->coef=p->coef+q->coef;
                r->index=p->index*q->index;
                Insert_Tail(head,r);
            }
        }
    }
    return head;
}

int main()
{
    int i=0,j,temp1,temp2;
    char choice;
    PolyNode *p,*head1,*head2,*q;
    head1=(PolyNode *)malloc(sizeof(PolyNode));
    head2=(PolyNode *)malloc(sizeof(PolyNode));
    head1->next=NULL;
    head2->next=NULL;
    q=head1;
    while(1)
    {
        printf("请输入表达式一的指数和系数:");
        scanf("%d %d",&temp1,&temp2);
        if(temp1==-1)
        {
            break;
        }
        if(temp2!=0)
        {
            p=(PolyNode *)malloc(sizeof(PolyNode));
            p->coef=temp1;
            p->index=temp2;
            p->next=q->next;
            q->next=p;
            q=p;
        }
        printf("%d\n",i++);
    }
    q=head2;
    while(1)
    {
        printf("请输入表达式二的指数和系数:");
        scanf("%d %d",&temp1,&temp2);
        if(temp1==-1)
        {
            break;
        }
        if(temp2!=0)
        {
            p=(PolyNode *)malloc(sizeof(PolyNode));
            p->coef=temp1;
            p->index=temp2;
            p->next=q->next;
            q->next=p;
            q=p;
        }
    }
    p=head1;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d\t%d\n",p->coef,p->index);
    } 
    p=head2;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d\t%d\n",p->coef,p->index);
    }
    getchar();
    printf("请输入你要进行的运算方式：1.+ 2. — 3. × :");
    choice=getchar();
    switch(choice)
    {
        case '1':
            Plus(head1,head2);
            break;
        case '2':
            Reduce(head1,head2);
            break;
        case '3':
            head1=Multiply(head1,head2);
            break;
    }
    p=head1;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d\t%d\n",p->coef,p->index);
    } 
}
