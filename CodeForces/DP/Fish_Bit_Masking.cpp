// ॐ मणि पद्मे हूँ
#include<bits/stdc++.h>
#ifdef Bis 
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
// template<typename T>
//using ordered_set= tree<T, null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
#define setbits  __builtin_popcountll
#define ll long long 
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ALL_THE(Cake,Lie) for(auto Lie = Cake.begin(); Lie!= Cake.end(); Lie++)
#define all(x) (x).begin(), (x).end()


constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

double prob[20][20];
double dp[(1<<19)];

double pMove(int prevmask, int j,int n){ // jth fish should die when set prevmask of fishes exist
    int k = __builtin_popcount(prevmask); // no of fishes alive currently
    ll den = k *(k-1)/2; // kC2

    double moveProb = 0;

    for(int fish = 0; fish <n; fish++){
        if(prevmask & (1 <<fish))
            moveProb +=  prob[fish][j]; // current fish eats jth fish
    }

    return moveProb / den *1.0;

}
double solve(int mask,int n)
{
    int alive = __builtin_popcount(mask); // number of fishes alive
    if(alive == n) // base condition cause initially all fishes are alive only
        return 1.0;

    if(dp[mask] > -0.9) // never compare floats directly 
        return dp[mask];
	
    double ans = 0;
    for(int fish = 0;fish < n;fish++){
        if(!((1 << fish) & mask)){ // if the fish is not alive at present
            int prevmask = mask ^ (1 << fish); // one day back he's alive
            double prevday = solve(prevmask,n); 
            ans += (prevday * pMove(prevmask, fish,n));
        }
    }

    return dp[mask] = ans;
}

signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
	#endif
    io;
    int t = 1;
    //cin>>t;

    cout << fixed << setprecision(10);
    while(t--){
        int n;
        cin >> n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i < n;i++)
            for(int j=0;j < n;j++) cin >> prob[i][j];

        for(int i=0;i < n;i++){
            cout << solve((1 << i),n) <<" ";
        }
        cout <<endl;

    }

    return 0;
}
//  https://codeforces.com/contest/16/problem/E
// https://www.youtube.com/watch?v=d7kvyp6dfz8&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=5
