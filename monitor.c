#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"

void up_Posi_Rider(output_riderptr current,int x_rid,int y_rid,int num_rid)
{
	current->num_rid=num_rid;
	current->x_rid = x_rid;
	current->y_rid = y_rid;
}

void up_Num_Rider(int riderNum,outputlistptr currentptr)
{
	riderNum = riderNum+1;
	currentptr->riderNum=riderNum;
}

void up_Time_Beg(int t,outputlistptr currentptr)
{
	t = t+1;
	currentptr->t=t;
}

void up_Time_Ord(int get_order,int t_stop[])
{
	int i=0;
	for(i=0;i<get_order;i++)
	{
		t_stop[i] = t_stop[i]-1;
	}
}//t_stop[]:the array of orders' remaining time 

void up_Visited_Res(int visited_Res[17][17],int x_res,int y_res,int flag)
{
	if(flag==1)
	{
		visited_Res[x_res][y_res]=1;
	}
	else if(flag==2)
	{
		visited_Res[x_res][y_res]=0;
	}
}
//visited_Res[17][17] (subscript:0~16);
//flag=1:we have visited this node,so we update the set
//flag=2:there is another same order, we need to change the value of node
//When the node is visited,the value is 1,else the value is 0

void up_Visited_Cli(int visited_Cli[17][17],int x_cli,int y_cli,int flag)
{
	if(flag==1)
	{
		visited_Cli[x_cli][y_cli]=1;
	}
	else if(flag==2)
	{
		visited_Cli[x_cli][y_cli]=0;
	}	
}

void up_Money(outputlistptr currentptr)
{
	int money;
	money=1000-300*(currentptr->riderNum)-50*(currentptr->overtime_order)+10*(currentptr->over_order);
    currentptr->pro=money;
}
//please prepare "currentptr=currentptr->next_time" in the simulate module
//please prepare "current=current->nextrider" in the simulate module
//@2019.5.19 Wu Chuanyv 
