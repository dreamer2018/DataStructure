/**********************************************************************************************
	> File Name: BinaryTree.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: 2015年10月28日 星期三 14时32分26秒
 *********************************************************************************************/

#include<stdio.h>
#include<malloc.h>

//定义数据类型
#define DataType char

//定义二叉树结构体
typedef struct BinaryTree
{
    DataType data;
    struct BinaryTree *LChild;
    struct BinaryTree *RChild;
}BiNode,* Bitree;


//递归方法创建二叉树(无返回值)
void Created_1(Bitree *root)
{
    char temp;
    temp=getchar();
    if(temp=='^')
    {
        *root=NULL;
    }
    else
    {

        *root=(Bitree)malloc(sizeof(BiNode));
        (*root)->data=temp;
        Created_1(&((*root)->LChild));
        Created_1(&((*root)->RChild));
    }
}
//递归方法创建二叉树(有返回值)
Bitree Created_2()
{
    char temp;
    temp=getchar();
    if(temp=='^')
    {
        return NULL;
    }
    Bitree s;
    s=(Bitree)malloc(sizeof(BiNode));
    s->data=temp;
    s->LChild=Created_2();
    s->RChild=Created_2();
    return s;
}
//先序遍历二叉树
void PreOrder(Bitree root)
{
    if(root)
    {
        printf("%c\t",root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}
//中序遍历二叉树
void InOrder(Bitree root)
{
    if(root)
    {
        InOrder(root->LChild);
        printf("%c\t",root->data);
        InOrder(root->RChild);
    }
}
//后序遍历二叉树
void PostOrder(Bitree root)
{
    if(root)
    {
        PostOrder(root->LChild);
        PostOrder(root->RChild);
        printf("%c\t",root->data);   
    }
}
//建立全局变量，用于统计节点个数
int count=0;
//统计二叉树的节点个数
void CountTree(Bitree root)
{
    if(root)
    {
        count++;
        CountTree(root->LChild);
        CountTree(root->RChild);
    }
}
//打印出节点
void PrintLeaf(Bitree root)
{
    if(root)
    {
        if(root->LChild==NULL&&root->RChild==NULL)
        {
            printf("%c\t",root->data);
        }
        PrintLeaf(root->LChild);
        PrintLeaf(root->RChild);
    }
}

//计算出叶子节点个数
int CountLeaf(Bitree root)
{
    int LCount,RCount;
    if(root==NULL)
    {
        return 0;
    }
    if(root->LChild==NULL && root->RChild==NULL)
    {
        return 1;
    }
    LCount=CountLeaf(root->LChild);
    RCount=CountLeaf(root->RChild);  
    return LCount+RCount;
}

//计算二叉树的高(非全局变量)
int CountHigh(Bitree root)
{
    int Lhigh,Rhigh,high;
    if(root==NULL)
    {
        return 0;
    }
    Lhigh=CountHigh(root->LChild);
    Rhigh=CountHigh(root->RChild);
    return high=(Lhigh>Rhigh ? Lhigh:Rhigh)+1;
}
//求度为二的结点
void CountDu(Bitree root)
{
    if(root)
    {
        if(root->LChild!=NULL&&root->RChild!=NULL)
        {
            printf("%c\t",root->data);
        }
        CountDu(root->LChild);
        CountDu(root->RChild);
    }
}
//左右子树的转置
void PreMerge(Bitree root)
{
    if(root)
    {
        Bitree temp;
        PreMerge(root->LChild);
        PreMerge(root->RChild);
        temp=root->LChild;
        root->LChild=root->RChild;
        root->RChild=temp;
        //printf("%c",root->data);
    }
}
int main()
{
    int Count=0,High;
    Bitree root;
    root=Created_2();
    /*
    //Created_1(&root);
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");

    PostOrder(root);
    printf("\n");
    CountTree(root);
    printf("count=%d\n",count);
    PrintLeaf(root);
    Count=CountLeaf(root);
    printf("\nCount=%d\n",Count);
    */
    //printf("du is %d",CountDu(root));
    //CountDu(root);
   // PreOrder(root);
   // printf("\n");
    //PreMerge(root);
    //PreOrder(root);
    //printf("\n");
}


