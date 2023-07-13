#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	b.emplace_back(a[0]);
	set<int>s;
	for(int i=1;i<n;i++)
		s.insert(s.end(),i);
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1]){
			b.emplace_back(a[i]);
			s.erase(s.find(i));
		}
	}
	for(auto i=s.begin();i!=s.end();i++) // remaining elements
		b.emplace_back(a[*i]);
	// for(int i=1;i<n;i++)
	// {
	// 	if(a[i]==a[i-1])
	// 		b.emplace_back(a[i]);
	// }
	for(int x:b)
		cout<<x<<" ";
	cout<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
