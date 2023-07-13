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

int par[100005][19];
int depth[100005];

unordered_map<int,vector<int>> graph;
const int LOG = 18;

void dfs(int node,int parent){
    par[node][0] = parent;
    depth[node] = depth[parent] +1;
    for(auto &x: graph[node]){
        if(x != parent){
            dfs(x,node);
        }
    }
}

int query(int node, int k){
    if(depth[node] <= k) // we can't have kth ancestor if the depth itself is less than k
        return 1;

    for(int i=0;i < LOG;i++){
        if((1 <<i) &k){
            node = par[node][i];
        }
    }

    return node;

}

void solve()
{
    int n;
    cin >> n;
    for(int i=0;i <n-1;i++){
        int u,v;
        cin >> u >>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    depth[0] = -1;
    dfs(1,0);


    // par[v][j] = 2^jth ancestor of node v
    for(int j=1;j <= LOG;j++){
        for(int v =1; v<=n;v++){
            par[v][j] = par[par[v][j-1]][j-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int node, k;
        cin >> node >> k;
        int ans = query(node,k);
        cout << ans <<"\n";
    }

}


signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
	#endif
    io;
    int t = 1;

    while(t--)
        solve();

    return 0;
}

