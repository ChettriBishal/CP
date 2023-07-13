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
void solve()
{
	int n,q;
    cin>>n>>q;
    vector<ll>a(n);
    ll ev=0,odd=0;
    for(ll &x:a){ 
        cin>>x;
        if(setbitsl(x)&1) odd++;
        else ev++;
    }
    while(q--){
        ll p;
        cin>>p; // the parity of xor array depends on the parity of p
        if(setbitsl(p)&1){  // if no of set bits is odd then overall parity count of b is opposite to that of a
            cout<<odd<<" "<<ev<<"\n";
        }
        else
            cout<<ev<<" "<<odd<<"\n";    // if no of set bits is even then overall parity count of b remains unchanged
    }
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

