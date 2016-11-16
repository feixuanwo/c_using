#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int arr[10][10]={0};//画出10*10=100个格子
	int row,col;//循环变量
	int row1,col1;//九宫格循环变量
	int count=0;//统计地雷的数量
	srand(time(0));//随机种子 配合rand函数来使用，每次执行的结果都不一样
	do
	{
		row=rand()%10;//row用来接收从0-9的随机数
		col=rand()%10;//col用来接收从0-9的随机数
		if(arr[row][col]==0)
		{
			arr[row][col]=-1;//标记为有地雷
			count++;
		}		
	}while(count<10);//从0-9就是10个

	for(row=0;row<10;row++)//行的遍历
	{
		for(col=0;col<=9;col++)//列的遍历
		{
			if(arr[row][col]!=-1)//如何没有地雷的情况下
			{
				count=0;
				for(row1=row-1;row1<=row+1;row1++)
				{
					for(col1=col-1;col1<=col+1;col1++)
					{
						if(((row1>=0&&row1<10)&&(col1>=0&&col1<=9))&&arr[row1][col1]==-1)
							count++;
					}
				}
				if(count==0)
					printf("0 ");
				else
					printf("%d ",arr[row][col]=count);//没地雷位置的值
			}
			else
				printf("* ");
		}
		printf("\n");
	}
    return 0;
}
