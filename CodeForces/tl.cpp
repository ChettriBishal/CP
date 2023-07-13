#include<bits/stdc++.h>
using namespace std; 
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
	io;
	int n,m;
	cin>>n>>m;
	vector<int>a(n),b(m);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	int l=*min_element(b.begin(),b.end());
	sort(a.begin(),a.end());
	int v=a[a.size()-1];
	int mul=a[0];
	vector<int>g;
	for(int i=v;i<l;i++)
	{
		if(i>=2*mul)
			g.push_back(i);
	}
	int res=-1;
	if(g.size()>0)
		res=*min_element(g.begin(),g.end());
	cout<<res<<endl;
	return 0;
}