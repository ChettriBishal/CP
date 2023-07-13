// https://discuss.codechef.com/t/crdflp-editorial/93982
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

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int &x : a) cin>>x;
    for(int &x: b) cin>>x;

    vector<int> state(n,-1);

    for(ll bit = 1<<29; bit >0 ;bit>>=1)
    {
        bool yes = true; // whether it's possible to have a set ith bit in the answer
        for(int i=0;i<n;i++){
            if(state[i] == 0 && !(a[i] & bit)) yes = false; // upward face
            else if(state[i] == 1 && !(b[i] & bit)) yes = false; // downward face
            else if(!( b[i] & bit) && !( a[i] & bit )) yes = false;
        }
        if(!yes ) continue;
        for(int i =0;i<n;i++){
            if(state[i] != -1) continue; // means the state has already been decided
            if(!( a[i] & bit )) state[i] = 1;  // b[i] can set current bit
            else if(!( b[i] & bit )) state[i] = 0; // a[i] can set current bit
        }
    }

    int res= ~0,flips =0;

    for(int bit=0;bit<n;bit++){
        if(state[bit] == 1){
            res &= b[bit];
            flips ++;
        }
        else
            res &= a[bit];
    }
    cout<<res<<" "<<flips<<endl;
    return ;

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

