#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#ifdef Bis 
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
using namespace std;
typedef long long ll;
#define setbits  __builtin_popcountll
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int wins(ll n)
{
    if(n == 0)
        return 0;
    // if n is odd
    if(n & 1ll){
        return !wins(n-1);
    }
    if(n % 4 != 0){
        return !wins(n/2ll);
    }
    return 1; // means the number is divisible by 4
}
void solve()
{
    long long n;
    cin>>n;
    if(wins(n)) // Alice starts the move
        cout<<"Alice\n";
    
    else
        cout<<"Bob\n";
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

