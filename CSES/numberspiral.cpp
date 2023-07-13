#include<iostream>
using namespace std;
void solve()
{
	long int x,y;
	cin>>x>>y;
	if(x<y)
	{
		if(y%2) // if y is odd
			cout<<y*y-x+1<<endl;
		else
			cout<<(y-1)*(y-1)+x<<endl;
	}
	else // x>y
	{
		if(x%2) // if x is odd
			cout<<(x-1)*(x-1)+y<<endl;
		else
			cout<<x*x-y+1<<endl;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}