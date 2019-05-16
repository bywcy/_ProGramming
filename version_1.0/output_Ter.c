#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"

void output_Ter(outputlistptr currentptr)
{
	int i=0;
	printf("时间：%d\n",currentptr->t);
	printf("钱：%d\n",currentptr->pro);
	printf("接单数：%d\n",currentptr->get_order);
	printf("完成数：%d\n",currentptr->over_order);
	printf("超时数：%d\n",currentptr->overtime_order);
	for(i=0;i<currentptr->riderNum;i++)
	{
		printf("骑手%d位置：%d, %d\n",currentptr->num_rid,currentptr->x_rid,currentptr->y_rid);
	}
}

