#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double res=0;
	int i=1;
	while(n-i>0)
	{
		res+=(double)n/(n-i);
		i++;
	}
	cout<<fixed<<setprecision(6);
	cout<<res<<endl;
	return 0;
}
