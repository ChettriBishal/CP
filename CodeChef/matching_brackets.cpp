#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,val;
	cin>>n;
	string a="";
	for(int i=0;i<n;i++)
	{
		cin>>val;
		a+=(val-1)?')':'(';
	}
	//cout<<a<<endl;
	vector<int>ans(4,0);
	int cnt=0,len=0,i=0; // len denotes the no of brackets in one balanced system
	while(i<n)
	{
		len++;
		if(a[i]=='(')
		{
			++cnt; // cnt to denote the depth (no of opening brackets)
			if(ans[0]<cnt)
			{
				ans[0]=cnt; // max no of opening brackets
				ans[1]=i+1; // position of the inner most (
			}
		}
		else{
			--cnt;
			if(cnt==0) // when brackets are balanced 
			{
				if(ans[2]<len)
				{
					ans[2]=len;
					ans[3]=i-len+2;
				}
				len=0;
			}
		}
		i++;
	}
	for(int x:ans)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
