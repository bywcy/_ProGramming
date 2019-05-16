#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "input_output.h"

orderlistptr input_File()//storage data with linked lists 
{
	int number=0,x_r=0,y_r=0,x_c=0,y_c=0,dist1=0,t0_0=0; 
	struct orderList *headptr=NULL,*currentptr=NULL,*lastptr=NULL,*temp;
	FILE *fptr;
	if((fptr=fopen("sales.txt","r"))!=NULL)
	{
		freopen("sales.txt","r",stdin);
		while(scanf("%d%d%d%d%d%d",&number,&t0_0,&x_r,&y_r,&x_c,&y_c)!=EOF)//create the list 
		{
			currentptr=malloc(sizeof(struct orderList));
			if(currentptr!=NULL)
			{
				if(headptr==NULL)
				{
					
					currentptr->num_order=number;
					currentptr->t0=t0_0;
					currentptr->x_res=x_r;
					currentptr->y_res=y_r;
					currentptr->x_cli=x_c;
					currentptr->y_cli=y_c;
					currentptr->dist=(int)sqrt((x_r-x_c)*(x_r-x_c)+(y_r-y_c)*(y_r-y_c));
					headptr=currentptr;
                    lastptr=currentptr;
				}
				else
				{
					currentptr->num_order=number;
					currentptr->t0=t0_0;
					currentptr->x_res=x_r;
					currentptr->y_res=y_r;
					currentptr->x_cli=x_c;
					currentptr->y_cli=y_c;
					currentptr->dist=(int)sqrt((x_r-x_c)*(x_r-x_c)+(y_r-y_c)*(y_r-y_c));
					lastptr->nextOrder=currentptr;
					lastptr=currentptr;					
				}
				lastptr->nextOrder=NULL;
			}
		}
	}
	fclose(stdin);
	fclose(fptr);
	return headptr;
}

/*
int main()
{
	orderlistptr currentptr;
	currentptr=malloc(sizeof(struct orderList));
	currentptr=input_File();
	while(currentptr!=NULL)
	{
		printf("Order_number%d\n",currentptr->num_order);
		currentptr=currentptr->nextOrder;
	}
	return 0;
}//for the test
*/
//2019.5.4   17:00p.m. Wu Chuanyv 
//2019.5.12  14:00p.m. Wu Chuanyv
//2019.5.14  19:56p.m. Wu Chuanyv change the freopen() to fopen()
//2019.5.14  21:24p.m. Wu Chuanyv 
