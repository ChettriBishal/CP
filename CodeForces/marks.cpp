#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
	io;
	int n,m;
	cin>>n>>m;
	vector<string>s;
	vector<vector<int>>a(m);
	for(int i=0;i<n;i++)
	{
		string g;
		cin>>g;
		s.push_back(g);
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			a[j].push_back(s[i][j]-'0');
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=0;j<m;j++)
		{
			int d=*max_element(a[j].begin(),a[j].end());
			if(s[i][j]-'0'==d)
			{
				flag=true;
				break;
			}
		}
		if(flag) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}