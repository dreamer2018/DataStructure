/*************************************************************************
	> File Name: 4.4.1.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility！
	> Created Time: Thu 08 Oct 2015 07:55:10 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int StrReplace(char *r,char c1,char c2)
{
    char *p;
    if(r==NULL)
    {
        return 0;
    }
    for(p=r;p<r+strlen(r);p++)
    {
        if(*p==c1)
        {
            *p=c2;
        }
    }
    return 1;
}

int StrReverse(char *r)
{
    int i;
    char *p,*q,t;
    if(r==NULL)
    {
        return 0;
    }
    for(i=0,p=r,q=r+strlen(r)-1;i<strlen(r)/2;i++,p++,q--)
    {
        t=*p;
        *p=*q;
        *q=t;
    }
}

int StrDelete(char *r,char ch)
{
    char *p,*q;
    if(r==NULL)
    {
        return 0;
    }
    for(p=r+strlen(r)-1;p>=r;p--)
    {
        if(*p==ch)
        {
            for(q=p;;q++)
            {
                *q=*(q+1);
                
                if(*(q+1)=='\0')
                {
                    break;
                }   
            }
        }
    }
    return 1;
}

int StrIndex(char *r1,char *r2,int index)
{
    int i,judge=0;
    char *p,*q;
    if(r1==NULL||r2==NULL)
    {
        return -1;
    }
    for(i=index,p=r1+index,q=r2;p<r1+strlen(r1);p++,i++)
    {
        if(*p==*q)
        {
            judge++;
            q++;
            if(judge==strlen(r2))
            {
                return i-judge+1;
            }
        }
        else
        {
            judge=0;
            q=r2;
        }
    }
    return -1;
}

int main()
{
    char r[20];
    scanf("%s",r);
    printf("%s\n",r);
    //StrReplace(r,'a','b');
    //StrReverse(r);
    //StrDelete(r,'a');
    int n=StrIndex(r,"lle",5);
    printf("%s\nn=%d\n",r,n);
}
