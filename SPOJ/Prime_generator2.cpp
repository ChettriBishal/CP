#include<iostream>
using namespace std;
int main()
{
	int t;
	long int a, b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a<=2)
		{
			a=2;
			cout<<a<<endl;
			a++;
		}
		if(a%2==0)
			a++;
		for(long int i=a;i<=b;i=i+2)
		{
			int f=0;
			for(long int j=2;j*j<=i;j++) // to check if individual number is prime or not
			{
				if(i%j==0){
					f=1;
					break;
				}
			}
			if(f==0)
				cout<<i<<endl;
		}
	}
	return 0;
}
