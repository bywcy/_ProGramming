#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct orderList//订单信息链表 
{
    int num_order;//订单编号 
    int x_res,y_res;//餐馆位置 
    int x_cli,y_cli;//食客位置 
    int dist;//餐馆与食客间路径长度 
    int t0;//初始时间 
    struct orderList *nextOrder;
}; 

typedef struct orderList orderlist;
typedef orderlist *orderlistptr;

orderlistptr input()//文件输入函数 
{
	int number=0,x_r=0,y_r=0,x_c=0,y_c=0,dist1=0,t0_0=0; //定义与订单信息中对应的变量 
	struct orderList *headptr=NULL,*currentptr=NULL,*lastptr=NULL,*temp;
	FILE *fptr;
	if((fptr=fopen("sales.txt","r"))!=NULL)
	{
		while(!feof(fptr))//创建链表 
		{
			fscanf(fptr,"%d",&number);
			fscanf(fptr,"%d",&t0_0);
			fscanf(fptr,"%d",&x_r);
			fscanf(fptr,"%d",&y_r);
			fscanf(fptr,"%d",&x_c);
			fscanf(fptr,"%d",&y_c);
			currentptr=(orderList*)malloc(sizeof(struct orderList));
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
	fclose(fptr);
	return headptr;
}

//2019.5.4 下午17:00 吴川宇 
