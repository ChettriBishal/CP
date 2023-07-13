#include<bits/stdc++.h> // greedy
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int i=s.find('*'); // first occurence of * // can use s.find_first_of('*') too
	int cnt=1;
	while(1)
	{
		int j=min(n-1,i+k); // the point is not to exceed the length
		while(s[j]=='.' && i<j)
			j--;
		if(i==j) // only one x
			break;
		cnt++;
		i=j;
	}
	cout<<cnt<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
