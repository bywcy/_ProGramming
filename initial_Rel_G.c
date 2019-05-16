#include<stdio.h>
#include<stdlib.h>
#include "input_output.h"

#define MAX 40

int RG[145][145];

int judgeRow(int index)
{
	int i,count=0,num=0;
	for(i=0;num<index;i++,count++)
	{
		if(i%2==0)	num+=8;
		else        num+=9;
	}
	return count;
}

int judgeCol(int row,int index)
{
	int col;
	int row1;//rows that have 8 indexes
	int row2;//rows that have 9 indexes
	
	row2=(row-1)/2;
	row1=row-1-row2;
	col=index-9*row2-8*row1;
	
	return col;
}

void initial_Rel_G()
{
	int i,j;
	int row1,col1,row2,col2;
	
	for(i=1;i<=144;i++)
	{
		for(j=1;j<=144;j++)
		{
			//transform the two indexes into coordinates
			row1=judgeRow(i);col1=judgeCol(row1,i);
			row2=judgeRow(j);col2=judgeCol(row2,j);
			
			if(row1%2==0)
			{
				if(((row1==row2)&&((col1-col2==1)||(col2-col1==1)))
				||((col1==col2)&&((row1-row2==1)||(row2-row1==1)))
				||((col1-col2==1)&&((row1-row2==1)||(row2-row1==1))))
				RG[i][j]=1;
			
				else if(i==j)
				RG[i][j]=0;
		    
			
				else 
				RG[i][j]=MAX;
		    }
		    
		    else
		    {
		    	if(((row1==row2)&&((col1-col2==1)||(col2-col1==1)))
				||((col1==col2)&&((row1-row2==1)||(row2-row1==1)))
				||((col2-col1==1)&&((row1-row2==1)||(row2-row1==1))))
				RG[i][j]=1;
			
				else if(i==j)
				RG[i][j]=0;
		    
			
				else 
				RG[i][j]=MAX;
			}
		}
	}
}

//#define test
#ifdef test
void outputArray(int array[][145],int rows,int cols)
{
	int row,col;
	for(row=1;row<rows;row++)
	{
		for(col=1;col<cols;col++)
		{
			if(col!=cols-1)
			printf("%d ",array[row][col]);
			else printf("%d\n",array[row][col]);
		}
	}
}

int main()
{
	int i,j;
	initial_Rel_G();
	for(i=1;i<30;i++)
	{
		for(j=1;j<30;j++)
		printf("RG[%d][%d]=%d\n",j,i,RG[j][i]);
	}
	outputArray(RG,30,30);//@2019.5.16 09:42 by Cui
}
#endif

//3.57 p.m. 2019.5.15 by Cui Siying

