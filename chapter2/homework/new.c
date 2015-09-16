/*************************************************************************
	> File Name: new.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Mon 14 Sep 2015 08:14:31 AM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

typedef struct student
{
    int id;
    struct student *next;
}stu;

stu *Tail()
{
    int id;
    stu *head,*p,*q;
    head=(stu *)malloc(sizeof(stu));
    head->next;
    p=head;
    while(1)
    {
        scanf("%d",&id);
        getchar();
        if(id<=0)
        {
            break;
        }
        q=(stu *)malloc(sizeof(stu));
        q->id=id;
        p->next=q;
        p=q;
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
    }
    q=p->next;
    p->next=s;
    p=p->next;
    p->next=q;
}

stu *Merge(stu *A ,stu *B)
{
    int m=0,n=0,i=0;
    stu *p,*q,*r,*s,*C;

    C=(stu *)malloc(sizeof(stu));

    //计算m,n的值
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
        for(i=0;i<m;i++)
        {
            
        }
    }
    else
    { 
        for(i=0;i<m;i++)
        {
        }
    }
    return C;
}
int main()
{
    int i=0;
    stu *head1,*head2,*head3,*p;
    head1=Tail();
    //head2=Tail();
    p=head1;
    while(p->next)
    {
        p=p->next;
        printf("%d\t",p->id);
    }
    p=(stu *)malloc(sizeof(stu));
    p->id=100;
    Insert(head1,p);
    p=head1;
    while(p->next)
    {
        printf("test");
        p=p->next;
        printf("%d\t",p->id);
    }
    printf("\n");
  /*  head3=Merge(head1,head2);

    p=head3;
    while(p)
    {
        i++;
        p=p->next;
        printf("%d\n",p->id);
    }*/
}

