/*************************************************************************
> File Name: linked_1.c
> Author: ZhouPan / github:dreamer2018 
> Mail: zhoupans_mail@163.com
> Blog: blog.csdn.net/it_dream_er
> Created Time: Mon 07 Sep 2015 04:00:50 PM CST
************************************************************************/

#include<stdio.h>
#include<malloc.h>

typedef struct student
{
    int id;
    float score;
    struct student *next;
}stu;

stu *Tail()
{
    int id;
    float score;
    stu *head,*p,*q;
    head=(stu *)malloc(sizeof(stu));
    p=head;
    while(1)
    {
        scanf("%d %f",&id,&score);
        getchar();
        if(id<=0)
        {
            break;
        }
        q=(stu *)malloc(sizeof(stu));
        q->id=id;
        q->score=score;
        p->next=q;
        p=p->next;
    }

    return head;
}

void Insert(stu *head,stu *s)
{
    stu *p,*q;
    p=head;
    while(p->next)
    {
        p=p->next;
        printf("%d \n",p->id);
    }
    q=p->next;
    p->next=s;
    p=p->next;
    p->next=q;
}
stu *Merge(stu *A,stu *B)
{
    int m=0,n=0,i=1;
    stu *p,*q,*r,*s,*t,*C;

    C=(stu *)malloc(sizeof(stu));
    
    p=A;
    while(p->next)
    {
        p=p->next;
        m++;
    }

    p=B;
    while(p->next)
    {
        p=p->next;
        n++;
    }

    printf("%d %d\n",m,n);
    C->next=NULL;
    q=C;
    s=A;
    r=B;
    if(m<=n)
    {
        while(i<=2*m)
        {
            if(i%2)
            {
                p=s->next;
                s=s->next;
            }
            else
            {
                p=r->next;
                r=r->next;
            }
            i++;
            Insert(C,p);   
        }
        p=C;
        while(r->next)
        {
            printf("test\n");
            t=q->next;
            q->next=r;
            q=q->next;
            q->next=t;
            r=r->next;
            printf("%d",p->id);
        }
    }
    else
    {
        while(i<=m)
        {
            q=p->next;
            if(i%2)
            {
                p=s->next;
                s=s->next;
            }
            else
            {
                p=r->next;
                r=r->next;
            }
            p=q;
            i++;
        }
        p->next=r;  
    }
    return C;
}

int main()
{
    int i=0;
    stu *head1,*head2,*head3,*p;
    head1=Tail();
    head2=Tail();
    p=head1;
    while(p->next)
    {
        p=p->next;
        printf("%d %3.2f\t",p->id,p->score);
    }
    printf("\n");
    p=head2;
    while(p->next)
    {
        p=p->next;
        printf("%d %3.2f\t",p->id,p->score);
    }
    printf("\n");
    head3=Merge(head1,head2);

    p=head3;
    printf("Test\n");
    while(p)
    {
        i++;
        printf("test\n");
        p=p->next;
        printf("%d %f\n",p->id,p->score);
    }
} 
