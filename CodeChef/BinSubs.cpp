#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define PI 3.141592653589793238
#ifdef bistimulus
#define focus(b) cerr<< (#b)<<" = ";cerr<<b;cerr<<endl;
#else
#define focus(b);
#endif
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve()
{
	int n;
    cin>>n;
    string s;
    cin>>s;
    vi ones(n+3,0); // count of 1's before i (a[i] is NOT included)
    vi zeroes(n+3,0); //count of 0's after i (a[i] is included)
    for(int i=1;i<=n;i++) // if a[i] is 1 for that value of i don't remove 1 from that index itself
        ones[i]=ones[i-1]+(s[i-1]=='1');
    for(int i=n-1;i>=0;i--)
        zeroes[i]=zeroes[i+1]+(s[i]=='0'); // contrast with ones
    int res=n;
    for(int i=0;i<=n;i++) // check the erasements possible for every index
        res=min(res,ones[i]+zeroes[i]);
    cout<<res<<"\n";
}
signed main()
{
    /*
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
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
