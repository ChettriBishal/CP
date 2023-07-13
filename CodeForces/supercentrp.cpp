#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int,int>>a;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		a.push_back(make_pair(x,y));
	}
	int spoints=0; //no of supercentral points
	for(int i=0;i<n;i++)
	{
		int e[]={0,0,0,0}; //count for the 4 distinct conditions
		int x1=a[i].first,y1=a[i].second;
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(a[j].first==x1 && a[j].second<y1) 
					e[0]++;
				if(a[j].first==x1 && a[j].second>y1) 
					e[1]++;
				if(a[j].first>x1 && a[j].second==y1) 
					e[2]++;
				if(a[j].first<x1 && a[j].second==y1) 
					e[3]++;
			}
		}
		if(e[0]>0 && e[1]>0 && e[2]>0 && e[3]>0) 
			spoints++; 
	}
	cout<<spoints<<endl;
	return 0;
}