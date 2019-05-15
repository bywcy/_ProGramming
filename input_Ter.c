#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "input_output.h"

orderlistptr input_Ter()////storage data with linked lists
{
    int number=0,x_r=0,y_r=0,x_c=0,y_c=0,dist1=0,t0_0=0; 
	struct orderList *headptr=NULL,*currentptr=NULL,*lastptr=NULL,*temp;
	while(scanf("%d%d%d%d%d%d",&number,&t0_0,&x_r,&y_r,&x_c,&y_c)!=EOF)
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
    return(headptr);
}

/* 
int main()
{
	orderlistptr currentptr;
	currentptr=malloc(sizeof(struct orderList));
	currentptr=input_Ter();
	while(currentptr!=NULL)
	{
		printf("订单信息：%d\n",currentptr->num_order);
		currentptr=currentptr->nextOrder;
	}
	return 0;
}//测试用 
*/
//2019.5.14 21:42 p.m. Wu Chuanyv
