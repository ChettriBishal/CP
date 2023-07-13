#include<bits/stdc++.h>
typedef long long ll;
#define rep(k,i,n) for(int i=k;i<n;i++)
using namespace std;
bool is_prime(ll x){
  if(x<=1) return false;
  for(ll i=2;i*i<=x;i++)
  if(x%i==0) return false;
  return true;
}
int xoro(int n)
{
	int r=n%4;
	if(r==0)
		return n;
	else if(r==1)
		return 1;
	else if(r==2)
		return n+1;
	else if(r==3)
		return 0;
}
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int val=0;
	for(int i=1;i<=n;i++)
		val=val^(xoro(k+i)^xoro(k+i+m));
	cout<<val<<endl;

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
