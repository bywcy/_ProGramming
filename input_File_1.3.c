#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "input_output.h"
int num_of_orders;
struct orderList_array orderlist_array[];

orderlistptr input_File()//storage data with linked lists 
{
	num_of_orders=0;
	int number=0,x_r=0,y_r=0,x_c=0,y_c=0,t0_0=0,i=0;
	struct orderList *headptr=NULL,*currentptr=NULL,*lastptr=NULL,*temp,*p=NULL;
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
					currentptr->t_end=t0_0+30;
					currentptr->x_res=x_r;
					currentptr->y_res=y_r;
					currentptr->x_cli=x_c;
					currentptr->y_cli=y_c;
					currentptr->dist=abs(x_r-x_c)/2+abs(y_r-y_c)/2-1;
					headptr=currentptr;
                    lastptr=currentptr;
                    num_of_orders++;
				}
				else
				{
					currentptr->num_order=number;
					currentptr->t0=t0_0;
					currentptr->t_end=t0_0+30;
					currentptr->x_res=x_r;
					currentptr->y_res=y_r;
					currentptr->x_cli=x_c;
					currentptr->y_cli=y_c;
					currentptr->dist=abs(x_r-x_c)/2+abs(y_r-y_c)/2-1;				
					lastptr->nextOrder=currentptr;
					lastptr=currentptr;
					num_of_orders++;					
				}
				lastptr->nextOrder=NULL;
			}
		}
	}
	fclose(stdin);
	fclose(fptr);
	p=(struct orderList*)malloc(sizeof(struct orderList)*num_of_orders);
	currentptr=headptr;
	for(i=0;i<num_of_orders;i++)
	{
	    orderlist_array[i].num_order=currentptr->num_order;
	    orderlist_array[i].t0=currentptr->t0;
	    orderlist_array[i].t_end=currentptr->t_end;
	    orderlist_array[i].x_res=currentptr->x_res;
	    orderlist_array[i].y_res=currentptr->y_res;
		orderlist_array[i].x_cli=currentptr->x_cli;
		orderlist_array[i].y_cli=currentptr->y_cli;
		orderlist_array[i].dist=currentptr->dist;	
		currentptr=currentptr->nextOrder;	
	}
	return headptr;
}
//after using it,we must free the *headptr and *currentptr
/*
currentptr=headptr;
while(currentptr->nextOrder!=NULL)
{
    temp=currentptr->nextOrder;
    free(currentptr);
    currentptr=temp;
}
free(currentptr);
headptr=NULL;
*/

/*
int main()
{
	int i=0;
	orderlistptr currentptr;
	currentptr=malloc(sizeof(struct orderList));
	currentptr=input_File();
	printf("num_of_orders£º%d\n",num_of_orders);
	while(currentptr!=NULL)
	{
		printf("Order_number in the list£º%d\n",currentptr->num_order);
		currentptr=currentptr->nextOrder;
	}
	for(i=0;i<num_of_orders;i++)
	{
	    printf("Order_number in the array£º%d\n",orderlist_array[i].num_order);
	}
	return 0;
}//for the test
*/

//2019.5.4   17:00p.m. Wu Chuanyv 
//2019.5.12  14:00p.m. Wu Chuanyv
//2019.5.14  19:56p.m. Wu Chuanyv change the freopen() to fopen()
//2019.5.14  21:24p.m. Wu Chuanyv 
//2019.5.18  23:57p.m. Wu Chuanyv make a struct array
