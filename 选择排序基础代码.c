//选择排序 实验
#include <stdio.h>

void selectsort(int * ,int );

int main(int argc, char const *argv[])
{
	int a[10]={5,5,6,3,3,8,0,9,12,1};

	selectsort(a ,10);

	return 0;
}

void selectsort(int *a ,int n)
{
	int temp=0 ,min=0;//min存储下标 注意初始化

	for(int i=0 ;i<n ;i++)
	{
		int min=i;

		for(int j=i+1 ;j<n ;j++)
			if(a[min]<a[j])
				min=j;
		
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}

	}

	for(int i=0 ;i<n ;i++)
		printf("%d ",a[i]);
}