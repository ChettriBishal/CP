// Special String 
// https://www.codechef.com/START24B/problems/SPECIALSTR
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
// template<typename T>
//using ordered_set= tree<T, null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define setbits  __builtin_popcountll
#define ll long long 
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

template<typename T> // cout << vector<vector<T>>
ostream& operator << (ostream &ostream,const vector<vector<T>> &vec){
    for(auto &row: vec){
        for(auto &el: row){
            cout << el <<" ";
        }
        cout <<"\n";
    }
    return ostream;
}

void solve()
{
    int n,m;
    string s;
    cin >> n >> s >> m;
    vector<int> index(26,n);
    vector<int> nxt(n,n);

    for(int i=n-1;i >=0;i--){
        int curr = s[i] -'a';
        nxt[i] = index[(curr + 1) % 26];
        index[curr] = i;
    }
    // create tree aka parent array
    // par[v][j] = 2 ^jth ancestor of v

    int LOG = log2(m) + 1;

    vector<vector<int>> par(n+1,vector<int>(LOG+1,n));

    for(int v= 0;v <n;v++) // 1st ancestor = parent
        par[v][0] = nxt[v];

    for(int j = 1;j <= LOG;j++){
        for(int v =0; v<n;v++){
            par[v][j] = par[par[v][j-1]][j-1];
        }
    }

    int res = INT_MAX;

    for(int i=0;i < n;i++){
        if(s[i] != 'a') 
            continue;
        int j= i, depth = m-1;
        for(int k = LOG-1;k >=0;k--){
            if((1 << k) <= depth){
                j = par[j][k];
                depth -= (1 << k);
            }
        }
        if(j != n){
            res = min(res, j - i +1 - m);
        }

    }
    if(res == INT_MAX)
        cout << -1 <<"\n";
    else 
        cout << res <<"\n";

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

