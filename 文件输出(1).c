#include <stdio.h>
#include <stdlib.h>

struct outputList//�����Ϣ���� 
{
    int pro,t;//�����ʱ�� 
	int get_order;//�ӵ��� 
	int over_order;//����� 
	int overtime_order;//��ʱ�� 
	int x_rid;//���ֺ����� 
	int y_rid;//���������� 
	int num_rid;//���ֱ�� 
	int riderNum;//�������ֵ�����
	struct outputList *next_time; 
}; 

typedef struct outputList outputlist;
typedef outputlist *outputlistptr;

void output(outputlistptr currentptr)//����������������Ϣ��������Ϣ������ļ��� 
{
	int i=0;
	FILE *fp;
	fp=fopen("output.txt","a+");
	fprintf(fp,"ʱ�䣺%d\n",currentptr->t);
	fprintf(fp,"Ǯ��%d\n",currentptr->pro);
	fprintf(fp,"�ӵ�����%d\n",currentptr->get_order);
	fprintf(fp,"�������%d\n",currentptr->over_order);
	fprintf(fp,"��ʱ����%d\n",currentptr->overtime_order);
    for(i=0;i<currentptr->riderNum;i++)
    {
    		fprintf(fp,"����%dλ�ã�%d , %d\n",currentptr->num_rid,currentptr->x_rid,currentptr->y_rid);
    }
	fclose(fp);		
}

//2019.5.6 ����18:00 �⴨�� 
 