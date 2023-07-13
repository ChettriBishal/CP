#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<string,int>scores;
	while(n--)
	{
		string s;
		cin>>s;
		scores[s]++;
	}
	int high=INT_MIN;
	string ans;
	for(auto i=scores.begin();i!=scores.end();i++)
	{
		if(i->second>high){
			high=i->second;
			ans=i->first;
		}
	}
	cout<<ans<<endl;
	return 0;
}
