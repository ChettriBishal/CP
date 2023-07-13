#include<iostream>
using namespace std;
int gx(int a,int b)
{
	int j=0,val=0;
	while(a||b)
	{
		if((a&1) && (b&1)) // where both contain a set bit
			val+=1<<j;
		j++;
		a>>=1; // right shift for traversing all the bits
		b>>=1;
	}
	return val;
}
void solve()
{
	int a,b;
	cin>>a>>b;
	int x= gx(a,b);
	cout<<(a^x)+(b^x)<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
/*
or simply x = a&b
and minimum value of sum = a^b
*/
