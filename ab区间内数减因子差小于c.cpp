#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,i,sum,k,j,t;
	scanf("%d%d%d",&a,&b,&c);
	for(k=0,i=a;i<=b;i++)
	{
		for(j=1,sum=0;j<i;j++)
		{
			if(i%j==0) sum+=j;
		}
		t=i-sum;
		if(fabs(t)<=c)
		{
			printf("%d\t",i);
			k++;
			if(k%5==0)printf("\n");
		}
	}
	if(k==0){printf("There is no proper number in the interval.");}
	printf("\n");
}
