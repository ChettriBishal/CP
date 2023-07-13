#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define n 1000000
using namespace std;
bool is_prime(ll x){
  if(x<=1) return false;
  for(ll i=2;i*i<=x;i++)
  if(x%i==0) return false;
  return true;
}
vector<bool> isprime(n+1,true);
vector<int>cnt(n+1,0);
void prime() //prime sieve
{
	isprime[0]=isprime[1]=false;
	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=n;j+=i)
				isprime[j]=false;
		}
	}
}
void count()
{
	for(int i=5;i<=n;i+=2)
	{
		int c=0;
		if(isprime[i] && isprime[i-2])
			c++;
		cnt[i]=cnt[i-1]+c;
		cnt[i+1]=cnt[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	prime();
	count();
	int t;
	cin>>t;
	while(t--)
	{
		int nn;
		cin>>nn;
		cout<<cnt[nn]<<endl;
	}
	// for(int i=0;i<15;i++)
	// 	cout<<i<<" ";
	// cout<<endl;
	// for(int i=0;i<15;i++)
	// 	cout<<cnt[i]<<" ";
	return 0;

}
