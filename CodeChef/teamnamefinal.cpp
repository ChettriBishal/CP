#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n; // no of funny words 
		cin>>n;
		vector<string>a(n); 
		for(int i=0;i<n;i++)
			cin>>a[i];
		vector<pair<string,int>>suf; // substring after the first letter
		for(int i=0;i<n;i++)
		{
			string b="";
			for(int j=1;j<a[i].size();j++)
				b+=a[i][j];
			suf.push_back(make_pair(b,i));
		}
		sort(suf.begin(),suf.end()); //sorting in lexographical order
		vector<int>c(n); 
		for(int i=1;i<n;i++) // different suffixes are gonna have different numbers
		{
			if(suf[i].first == suf[i-1].first)
				c[suf[i].second]=c[suf[i-1].second];
			else 
				c[suf[i].second]=c[suf[i-1].second]+1;
		}
		vector<vector<bool>> funny(26,vector<bool>(n,false));
		for(int i=0;i<n;i++) // first index= first letter number // second index= suffix number
			funny[a[i][0]-'a'][c[i]]=true; //funny words are marked as true
		int res=0;
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
				int cnt_10=0, cnt_01=0;
				for(int k=0;k<n;k++)
				{
					if(funny[i][k] && !funny[j][k])
						cnt_10++;
					else if(!funny[i][k] && funny[j][k])
						cnt_01++;
				}
				res+=cnt_01*cnt_10;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}