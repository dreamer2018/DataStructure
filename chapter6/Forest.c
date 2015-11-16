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
#define char DATATYPE

//定义森林的数据结构
typedef struct forest
{
    DATATYPE data;
    struct forest FirstChild;
    struct forest NextSibling;
}ForestNode;

//先序创建森林
void Created(ForestNode *f)
{
    DATATYPE ch;
    ch=getchar();
    if(ch=='^')
    {
        f=NULL;
    }
    else
    {
        f->data=ch;
        Created(f->FirstChild);
        Created(f->NextSibling);
    }
}

//先根便利二叉树
void RootFirst(ForestNode *f)
{
    ForestNode *t;
    t=f;
    if(t!=NULL)
    {
        printf("%c\t",f->data);
        while(t)
        {
            t=t->FirstChild;

        }
    }
}
int main()
{
    
}
