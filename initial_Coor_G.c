#include<stdio.h>
#include "initialize.h"

#ifndef RES
#define RES 1
#endif

#ifndef CLI
#define CLI 2
#endif

#ifndef RO
#define RO 0
#endif

#ifndef INV
#define INV -1
#endif//mark the indexes that are not assigned the identity


COOR_G CG[17][17];
ind_xy roadIndex[145];
ind_xy cliIndex[80];
ind_xy resIndex[80];
//@2019.5.16 08:50 by Cui

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
				a[i][j].tag=RO;//road
				if(i%2==1&&j%2==1) a[i][j].index=RO;
			    else
			    {
			    	a[i][j].index=id;
			    	roadIndex[id].x=i;
			    	roadIndex[id].y=j;
			    	id++;
				}
			    
		    }
			else //not road
			{
				a[i][j].tag=INV;
				a[i][j].index=INV;//the index and the tag will be given values later in the assigning function 
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
				a[i][j].arou[1].tag=RO;
				a[i][j].arou[1].index=a[i][j-1].index;
			}
			else 
			{
				a[i][j].arou[1].tag=INV;
				a[i][j].arou[1].index=INV;
			}
			
			a[i][j].arou[2].x=i;a[i][j].arou[2].y=j+1;
			if(i%2==1||(j+1)%2==1)
			{
				a[i][j].arou[2].tag=RO;
				a[i][j].arou[2].index=a[i][j+1].index;
			}
			else 
			{
				a[i][j].arou[2].tag=INV;
				a[i][j].arou[2].index=INV;
			}
			
			a[i][j].arou[3].x=i-1;a[i][j].arou[3].y=j;
			if((i-1)%2==1||(j%2==1))
			{
				a[i][j].arou[3].tag=RO;
				a[i][j].arou[3].index=a[i-1][j].index;
			}
			else 
			{
				a[i][j].arou[3].tag=INV;
				a[i][j].arou[3].index=INV;
			}
			
			a[i][j].arou[4].x=i+1;a[i][j].arou[4].y=j;
			if((i+1)%2==1||j%2==1)
			{
				a[i][j].arou[4].tag=RO;
				a[i][j].arou[4].index=a[i+1][j].index;
			}
			else 
			{
				a[i][j].arou[4].tag=INV;
				a[i][j].arou[4].index=INV;
			}
		}
	}
}

#define test
#ifdef test
//@2019.05.15 09:15 by LI :/
void outputXY(COOR_G array[][17],int rows,int cols)
{
	int row,col;
	for(row=0;row<=rows;row++)
	{
		for(col=0;col<=cols;col++)
		{
			printf("(%d,%d) id=%d\n",array[col][row].x,array[col][row].y,array[col][row].index);
			//@2019.5.16 9:24 by Cui
			printf("up=(%d,%d) id=%d ",array[col][row].arou[1].x,array[col][row].arou[1].y,array[col][row].arou[1].index);
			printf("down=(%d,%d) id=%d ",array[col][row].arou[2].x,array[col][row].arou[2].y,array[col][row].arou[2].index);
			printf("left=(%d,%d) id=%d ",array[col][row].arou[3].x,array[col][row].arou[3].y,array[col][row].arou[3].index);
			printf("right=(%d,%d) id=%d\n ",array[col][row].arou[4].x,array[col][row].arou[4].y,array[col][row].arou[4].index);
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
 	int i;
 	initial_Coor_G(CG);
	outputXY(CG,16,16);
	outputArray(CG,17,17);
	for(i=1;i<=144;i++) printf("roadIndex[%d]=(%d,%d)\n",i,roadIndex[i].x,roadIndex[i].y);
	}
 #endif
 
 //2019.5.12 11:31 by Cui Siying 
 //2019.5.15 16:06 by Cui Siying
