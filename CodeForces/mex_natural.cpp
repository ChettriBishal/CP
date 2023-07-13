#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int>a(n),b;
	for(int &x:a)
		cin>>x;
	sort(a.begin(),a.end());
	// for(int x:a)
	// 	cout<<x<<" ";
	// cout<<endl;
	b.push_back(a[0]);
	for(int i=1;i<n;i++)
		if(a[i]!=a[i-1]) // unequal consecutive
			b.push_back(a[i]);
	for(int i=1;i<n;i++)
		if(a[i]==a[i-1])  // equal consecutive added at the end
			b.push_back(a[i]);
	for(int x:b)
		cout<<x<<" ";
	cout<<endl;
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
