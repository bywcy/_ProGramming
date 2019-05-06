#include <stdio.h>
#include <stdlib.h>

struct outputList//输出信息链表 
{
    int pro,t;//收益和时间 
	int get_order;//接单数 
	int over_order;//完成数 
	int overtime_order;//超时数 
	int x_rid;//骑手横坐标 
	int y_rid;//骑手纵坐标 
	int num_rid;//骑手编号 
	int riderNum;//所需骑手的数量
	struct outputList *next_time; 
}; 

typedef struct outputList outputlist;
typedef outputlist *outputlistptr;

void output(outputlistptr currentptr)//输出函数：将输出信息链表中信息输出到文件中 
{
	int i=0;
	FILE *fp;
	fp=fopen("output.txt","a+");
	fprintf(fp,"时间：%d\n",currentptr->t);
	fprintf(fp,"钱：%d\n",currentptr->pro);
	fprintf(fp,"接单数：%d\n",currentptr->get_order);
	fprintf(fp,"完成数：%d\n",currentptr->over_order);
	fprintf(fp,"超时数：%d\n",currentptr->overtime_order);
    for(i=0;i<currentptr->riderNum;i++)
    {
    		fprintf(fp,"骑手%d位置：%d , %d\n",currentptr->num_rid,currentptr->x_rid,currentptr->y_rid);
    }
	fclose(fp);		
}

//2019.5.6 下午18:00 吴川宇 
 