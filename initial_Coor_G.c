#include<stdio.h>
#include "initialize.h"

COOR_G CG[17][17];

void initial_Coor_G(COOR_G a[][17])
{
	int i,j;
	int id=1;//mark indexes of the road
	for(j=0;j<=16;j++)
	{
		for(i=0;i<=16;i++)
		{
			//initialize tag
			if(i%2==1||j%2==1)
			{
				a[i][j].tag=0;//road
				if(i%2==1&&j%2==1) a[i][j].index=0;
			    else
			    {
			    	a[i][j].index=id;
			    	id++;
				}
			    
		    }
			else //not road
			{
				a[i][j].tag=-1;
				a[i][j].index=-1;//the index and the tag will be given values later in the assigning function 
			}
			
			//intialize the coordinates of every index
			a[i][j].x=i;
			a[i][j].y=j;
		}
	}
	for(i=0;i<=16;i++)
	{
		for(j=0;j<=16;j++)
		{
			//intialize the arounding indexes'coordinates of every index
			a[i][j].arou[1].x=i;a[i][j].arou[1].y=j-1;
			if(i%2==1||(j-1)%2==1)
			{
				a[i][j].arou[1].tag=0;
				a[i][j].arou[1].index=a[i][j-1].index;
			}
			else 
			{
				a[i][j].arou[1].tag=-1;
				a[i][j].arou[1].index=-1;
			}
			
			a[i][j].arou[2].x=i;a[i][j].arou[2].y=j+1;
			if(i%2==1||(j+1)%2==1)
			{
				a[i][j].arou[2].tag=0;
				a[i][j].arou[2].index=a[i][j+1].index;
			}
			else 
			{
				a[i][j].arou[2].tag=-1;
				a[i][j].arou[2].index=-1;
			}
			
			a[i][j].arou[3].x=i-1;a[i][j].arou[3].y=j;
			if((i-1)%2==1||(j%2==1))
			{
				a[i][j].arou[3].tag=0;
				a[i][j].arou[3].index=a[i-1][j].index;
			}
			else 
			{
				a[i][j].arou[3].tag=-1;
				a[i][j].arou[3].index=-1;
			}
			
			a[i][j].arou[4].x=i+1;a[i][j].arou[4].y=j;
			if((i+1)%2==1||j%2==1)
			{
				a[i][j].arou[4].tag=0;
				a[i][j].arou[4].index=a[i+1][j].index;
			}
			else 
			{
				a[i][j].arou[4].tag=-1;
				a[i][j].arou[4].index=-1;
			}
		}
	}
}

//#define test
#ifdef test
//@2019.05.15 09:15 by LI :/
void outputXY(COOR_G array[][17],int rows,int cols)
{
	int row,col;
	for(row=0;row<=rows;row++)
	{
		for(col=0;col<=cols;col++)
		{
			printf("(%d,%d) ",array[row][col].x,array[row][col].y);
			printf("up=(%d,%d) id=%d ",array[row][col].arou[1].x,array[row][col].arou[1].y,array[row][col].arou[1].index);
			printf("down=(%d,%d) id=%d ",array[row][col].arou[2].x,array[row][col].arou[2].y,array[row][col].arou[2].index);
			printf("right=(%d,%d) id=%d ",array[row][col].arou[4].x,array[row][col].arou[4].y,array[row][col].arou[4].index);
			printf("left=(%d,%d) id=%d\n",array[row][col].arou[3].x,array[row][col].arou[3].y,array[row][col].arou[3].index);
		}
	}
}

void outputArray(COOR_G array[][17],int rows,int cols)
{
	int row,col;
	for(row=0;row<rows;row++)
	{
		for(col=0;col<cols;col++)
		{
			if(col!=cols-1)
			printf("(%d,%d)   ",array[col][row].tag,array[col][row].index);
			else printf("(%d,%d)\n",array[col][row].tag,array[col][row].index);
		}
	}
}

 int main()
 {
 	initial_Coor_G(CG);
	outputXY(CG,16,16);
	outputArray(CG,17,17);
 }
 #endif
 
 //2019.5.12 11:31 by Cui Siying 
 //2019.5.15 16:06 by Cui Siying
