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

template<typename T> // to display 2D vector
ostream& operator << (ostream &ostream,const vector<vector<T>> &vec){
    for(auto &row: vec){
        for(auto &el: row){
            cout << el <<" ";
        }
        cout <<"\n";
    }
    return ostream;
}

constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

ll own[11][101];
ll dp[101][(1 << 11)];


ll getways(int shirt, int mask,int n){
    if(mask == (1 <<n)-1) // all people were assigned shirts
        return 1;

    if(shirt > 100) return 0;

    if(dp[shirt][mask] != -1)
        return dp[shirt][mask];

    ll res = 0;

    for(int i =0;i < n;i++){
        // if the person is not wearing any shirt and also owns the current t shirt
        if((mask & (1 << i)) == 0 && own[i][shirt]){
            ll val = getways(shirt+1, mask | (1 << i), n) % MOD;
            res = (res + val) % MOD;
        }
    }

    ll notassigned = getways(shirt+1,mask, n) % MOD;

    res = (res + notassigned) % MOD;

    return dp[shirt][mask] = res;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    memset(own,0,sizeof(own));
    memset(dp,-1,sizeof(dp));
    cin.ignore();
    for(int i=0;i <n;i++){
        getline(cin,s);
        stringstream in(s);
        int shirt;
        while(in >> shirt){
            own[i][shirt] = 1;
        }
    }

    cout << getways(1,0,n) << endl;
	
}

signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
	#endif
    io;
    int t = 1;
    cin>>t;

    while(t--)
        solve();

    return 0;
}

