#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define setbitsi  __builtin_popcount
#define setbitsl  __builtin_popcountll
#define rep(i,k,n) for(int i=k;i<n;i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define PI 3.141592653589793238
#ifdef bistimulus
#define focus(b) cerr<< (#b)<<" = ";cerr<<b;cerr<<endl;
#else
#define focus(b);
#endif
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
void solve()
{
    ll n;
    cin>>n;
    ll d,sum=0,q;
    rep(i,0,n){
        cin>>d;
        sum+=(d%mod+mod)%mod; // +mod will affect only if the value is negative
    }
    if(sum<0) sum+=mod;
    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        sum+=sum;
        sum=(sum%mod+mod)%mod;
        cout<<sum<<"\n";
    }	
}
signed main()
{
    io;
    int t=1;
    //cin>>t;
	#ifdef bistimulus
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
    while(t--)
        solve();
	#ifdef bistimulus
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr <<endl<< "Time Elapsed: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
    return 0;
}
/*
 * Consider this 
 * -8 % 5 gives -3 however the answer is actually 2 (-3 + 5)
 *  hence if we need to find a%b and a<0 then 
 *  a % b is a%b + b 
 *  a%b in general terms is a- (a/b)*b
 *
 *  https://discuss.codechef.com/t/arrrot-editorial/88770/13
 */
 
