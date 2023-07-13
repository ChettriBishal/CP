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
#define arrsize 1e5
void solve()
{
    vector<int> weights(arrsize+3,0);
    int n,d,w,wr;
    cin>>n>>w>>wr;
    set<int>ind; // set to store the values which also serve as index
    rep(i,0,n){
        cin>>d;
        ind.insert(d);
        weights[d]++;
    }
    ll res=wr;
    for(auto i=ind.begin();i!=ind.end();i++)
        res+=(ll) (*i)* 2*(weights[*i]/2);
    if(res>=w) cout<<"YES\n";
    else cout<<"NO\n";

}
signed main()
{
    io;
    int t;
    cin>>t;
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
https://discuss.codechef.com/t/benchp-editorial/88774
*/
