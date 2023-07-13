#include<bits/stdc++.h>
#define int long long
#define n 1000001
using namespace std;
vector<int>cnt(n+1,0);
vector<bool> isprime(n+1,true);
void prime() //prime sieve
{
	int c=0;
	isprime[0]=isprime[1]=false;
	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=n;j+=i)
				isprime[j]=false;
		}
	}
	for(int i=2;i<=n;i++) //prefix sum storing count till nth term
		cnt[i]=cnt[i-1]+(int)isprime[i];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	prime();
	int t;
	cin>>t;
	while(t--)
	{
		int x,d;
		cin>>x>>d;
		//cout<<cnt[x]<<" ";
		if(cnt[x]<=d)
			cout<<"Chef\n";
		else 
			cout<<"Divyam\n";
	}
	return 0;
}
