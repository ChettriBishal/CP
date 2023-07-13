#include<stdio.h>
int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			switch(i){
				case 0:
					for(int k=0;k<(n-1)-j;k++)
						printf(" ");
					for(int k=0;k<j+1;k++)
						printf(" *");
					break;
				case 1:
					for(int k=0;k<j;k++)
						printf(" ");
					for(int k=0;k<n-j;k++)
						printf(" *");
			}
			printf("\n");
		}
	}
	return 0;
}
