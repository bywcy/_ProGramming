#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct orderList//������Ϣ���� 
{
    int num_order;//������� 
    int x_res,y_res;//�͹�λ�� 
    int x_cli,y_cli;//ʳ��λ�� 
    int dist;//�͹���ʳ�ͼ�·������ 
    int t0;//��ʼʱ�� 
    struct orderList *nextOrder;
}; 

typedef struct orderList orderlist;
typedef orderlist *orderlistptr;

orderlistptr input()//�ļ����뺯�� 
{
	int number=0,x_r=0,y_r=0,x_c=0,y_c=0,dist1=0,t0_0=0; //�����붩����Ϣ�ж�Ӧ�ı��� 
	struct orderList *headptr=NULL,*currentptr=NULL,*lastptr=NULL,*temp;
	FILE *fptr;
	if((fptr=fopen("sales.txt","r"))!=NULL)
	{
		while(!feof(fptr))//�������� 
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

//2019.5.4 ����17:00 �⴨�� 
