/*************************************************************************
	> File Name: 1.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Thu 24 Sep 2015 09:06:08 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,len_1,len_2;
    char choice;
    int num1[100],num2[100],num3[100];
    memset(num1,0,100*sizeof(int));
    memset(num2,0,100*sizeof(int));
    memset(num3,0,100*sizeof(int));
    printf("请输入表达式一最高次项的指数：");
    scanf("%d",&len_1);
    for(i=0;i<=len_1;i++)
    {
        printf("请输入%d次项的系数:",i);
        scanf("%d",&num1[i]);
    }
    for(i=0;i<=len_1;i++)
    {
        printf("%d\t",num1[i]);
    }

    printf("\n");
    
    printf("请输入表达式二最高次项的指数：");
    scanf("%d",&len_2);
    for(i=0;i<=len_2;i++)
    {
        printf("请输入%d次项的系数:",i);
        scanf("%d",&num2[i]);
    }
    for(i=0;i<=len_2;i++)
    {
        printf("%d\t",num2[i]);
    }
    printf("\n");
    getchar();
    printf("你要进行哪种运算：1.+ 2. — 3. × :");
    choice=getchar();
    switch(choice)
    {
        case '1':   //加
            if(len_1>len_2)
            {
                for(i=0;i<=len_1;i++)
                {
                    num1[i]+=num2[i];
                }
            }
            else
            {
                for(i=0;i<=len_2;i++)
                {
                    num1[i]+=num2[i];
                }
            }
            break;
        case '2':   //减
            if(len_1>len_2)
            {
                for(i=0;i<=len_1;i++)
                {
                    num1[i]-=num2[i];
                }
            }
            else
            {
                for(i=0;i<=len_2;i++)
                {
                    num1[i]-=num2[i];
                }
            }
            break;
        case '3':   //乘
            for(i=0;i<=len_1;i++)
            {
                for(j=0;j<=len_2;j++)
                {
                    num3[i+j]+=num1[i]*num2[j];
                    //printf("%d\t%d\n",i+j,num3[i+j]);
                }
            }
            break;
    }
    if(choice=='1'||choice=='2')
    {
        if(len_1>len_2)
        {
            for(i=0;i<=len_1;i++)
            {
                printf("%d\t",num1[i]);
            }
        }
        else
        {
            for(i=0;i<=len_2;i++)
            {
                printf("%d\t",num1[i]);
            }
        }
    }
    else
    {
        for(i=0;i<=len_1+len_2;i++)
        {
            printf("%d\t",num3[i]);
        }
    }
    printf("\n");
}
