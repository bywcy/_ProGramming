#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"

void output_File(outputlistptr currentptr) 
{
	int i=0;
	freopen("output.txt","a+",stdout);
	printf("时间：%d\n",currentptr->t);
	printf("钱：%d\n",currentptr->pro);
	printf("接单数：%d\n",currentptr->get_order);
	printf("完成数：%d\n",currentptr->over_order);
	printf("超时数：%d\n",currentptr->overtime_order);
	for(i=0;i<currentptr->riderNum;i++)
	{
		printf("骑手%d位置：%d, %d\n",currentptr->num_rid,currentptr->x_rid,currentptr->y_rid);
	}
    fclose(stdout);
}

//2019.5.6  18:00p.m. Wu Chuanyv
//2019.5.12 14:05p.m. Wu Chuanyv 
 

