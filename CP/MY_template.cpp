#include<bits/stdc++.h>
#ifdef Bis 
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
// change int when required 
//using bis_set= tree<int, null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update>;
#define setbits  __builtin_popcountll
#define rep(i,k,n) for(int i=k;i<n;i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
bool is_prime(ll x){ // check for prime
  if(x<=1) return false;
  for(ll i=2;i*i<=x;i++)
  if(x%i==0) return false;
  return true;
}
vector<bool> prime(int n) //prime sieve
{
	vector<bool> isprime(n+1,true);
	isprime[0]=isprime[1]=false;
	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=n;j+=i)
				isprime[j]=false;
		}
	}
	return isprime;
}
void solve()
{
	
}
signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
    io;
    int t;
    cin>>t;
    while(t--)
        solve();
	#ifdef Bis
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr <<endl<< "Time Elapsed: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
    return 0;
}
