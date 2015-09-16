/*************************************************************************
	> File Name: Stack_Test.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Tue 15 Sep 2015 09:27:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef char ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int top;
}StackNode;

void Init(StackNode *S)
{
    S->top=-1;
}

int Push(StackNode *S,ElemType e)
{
    if(S->top>=MAXSIZE-1)
    {
        printf("Stack is full!\n");
        return 0;
    }
    S->top++;
    S->elem[S->top]=e;
    return 1;
}

int Pop(StackNode *S,ElemType *e)
{
    if(S->top<0)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    *e=S->elem[S->top];
    S->top--;
}

int Match(ElemType c,ElemType e)
{
    if(c=='{'&&e=='}')
    {
        return 1;
    }
    else if(c=='['&&e==']')
    {
        return 1;
    }
    else if(c=='('&&e==')')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main()
{
    int i=-1,count=-1;
    ElemType e,elem[MAXSIZE];
    StackNode *S;
    S=(StackNode *)malloc(sizeof(StackNode));
    Init(S);
    while(1)
    {
        count++;
        scanf("%c",&e);
        if(e=='\n'||count>=MAXSIZE-1)
        {
            count--;
            break;
        }
        elem[count]=e;
    }
    printf("%d\n",count);
    while(i<count)
    {   
        i++;
        switch(elem[i])
        {
            case '{':
            case '[':
            case '(':
                Push(S,elem[i]);
                break;
            case '}':
            case ']':
            case ')':
                if(i!=count&&S->top==-1)
                {
                    printf("Not match,right to much!\n");
                    exit(0);
                }
                Pop(S,&e);
                if(Match(e,elem[i]))
                {
                    if(i==count&&S->top==-1)
                    {
                        printf("Match!\n");
                    }
                    else if(i==count && S->top!=-1)
                    {   
                        printf("Not match,left to much!\n");
                        exit(0);
                    }
                }
                else   
                {
                    printf("not match!\n");
                    exit(0);
                }
                break;
            default:
                printf("character is error!\n");
                exit(0);
        }
    }
}
