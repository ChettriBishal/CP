// ॐ मणि पद्मे हूँ

// https://www.codechef.com/problems/MSTQS
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

#define ALL_THE(CAKE,LIE) for(auto LIE = CAKE.begin(); LIE != CAKE.end(); LIE++)

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

int findP(int x,vector<int>& parent){
    if(parent[x] == -1){
        return x;
    }

    return parent[x] = findP(parent[x], parent);
}

bool Union(int x, int y, vector<int>&rank, vector<int>& parent){
    int s1 = findP(x,parent); // parent of x 
    int s2 = findP(y,parent); // parent of y

    if(s1 == s2){ // could not union as both belong to the same set
        return false;
    }
    if(rank[s1] < rank[s2]){
        parent[s1] = s2;
        rank[s2] += rank[s1];
    }
    else{
        parent[s2] = s1;
        rank[s1] += rank[s2];
    }
    return true;
}

ll getMST(set<pair<ll,pair<int,int>>>& mstEdges,vector<int> & rank,vector<int>& parent){
    ll weight = 0;
    int cnt = 0;
    for(auto &edge: mstEdges){
        int u,v;
        ll w;
        w = edge.f;
        u = edge.s.f;
        v = edge.s.s;
        if(Union(u,v,rank,parent)){
            weight += w;
            cnt++;
        }
        if(cnt >= (int) rank.size()-2) break;
    }
    return weight;
}

void solve()
{
    set<pair<ll,pair<int,int>>> edges;
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i < m;i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        edges.insert({w,{u,v}});
    }

    set<pair<ll,pair<int,int>>> mstEdges; // those edges that actually contribute to mst

    vector<int> parent(n+1,-1);
    vector<int> rank(n+1,0);
    ll res = 0;

    for(auto &edge: edges){
        int u,v;
        ll w;
        w = edge.f;
        u = edge.s.f, v = edge.s.s;
        if(u > v) swap(u,v);
        if(Union(u,v,rank,parent)){
            mstEdges.insert({w,{u,v}});
            res += w;
        }
    }
    
    bool computeagain = false;

    while(q--){
        int qt, u,v;
        cin >> qt;
        if(qt == 1){
            cin >> u >> v;
            if(u > v) swap(u,v);
            mstEdges.insert({0,{u,v}});
            computeagain = true;
        }
        else if(qt == 2){
            cin >> u >> v;
            if(u > v) swap(u,v);
            if(mstEdges.find({0,{u,v}}) != mstEdges.end()){
                mstEdges.erase({0,{u,v}});
            }
            computeagain = true;
        }
        else{
            if(!computeagain){
                cout << res << "\n";
                continue;
            }
            fill(rank.begin(),rank.end(),0);
            fill(parent.begin(),parent.end(),-1);
            res = getMST(mstEdges,rank,parent);
            cout << res <<"\n";
            computeagain = false;
        }
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

