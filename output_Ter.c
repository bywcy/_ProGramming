#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"

void output_Ter(outputlistptr currentptr)
{
	int i=0;
	printf("ʱ�䣺%d\n",currentptr->t);
	printf("Ǯ��%d\n",currentptr->pro);
	printf("�ӵ�����%d\n",currentptr->get_order);
	printf("�������%d\n",currentptr->over_order);
	printf("��ʱ����%d\n",currentptr->overtime_order);
	for(i=0;i<currentptr->riderNum;i++)
	{
		printf("����%dλ�ã�%d, %d\n",currentptr->num_rid,currentptr->x_rid,currentptr->y_rid);
	}
}

