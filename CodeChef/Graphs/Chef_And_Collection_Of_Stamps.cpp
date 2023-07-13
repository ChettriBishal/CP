// ॐ मणि पद्मे हूँ

#include<bits/stdc++.h>
#include<cstdio>
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
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
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
const int mx = 5e4;

inline void solve()
{
    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> vec(mx+3);

    unordered_map<int,int> tp;

    for(int i=0;i < n;i++){
        int x;
        cin >> x;
        tp[x]++;
    }

    for(int i=0;i < m;i++){
        int d, a,b;
        cin >> d >> a >> b;
        vec[d].push_back({a,b});
    }

    int max_type[mx+3]; // maximum type into which a stamp of type t can exchanged into 

    for(int i=0;i <=mx;i++) max_type[i] = i;

    for(int i= mx;i >=0;i--){ // reverse chronological order 
        unordered_map<int,vector<int>> graph;
        // for a particular day 
        for(auto &x: vec[i]){
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }

        vector<vector<int>> comp; // to store the component array for every subgraph associated to time T

        unordered_map<int,int> vis;
        int C = 0;
        ALL_THE(graph,it){
            if(vis.find(it->first) == vis.end()){
                vis[it->first] = C;
                queue<int> q;
                vector<int> v;

                q.push(it->first);
                while(!q.empty()){
                    int node = q.front();
                    v.push_back(node);
                    q.pop();

                    ALL_THE(graph[node],jt){
                        if(vis.find(*jt) == vis.end()){
                            q.push(*jt);
                            vis[*jt] = C;
                        }
                    }
                }
                C++;
                comp.push_back(v); // one sub-graph consisting of connected components inserted 
            }
        }

        for(int j=0;j < (int) comp.size();j++){
            int val = -1;
            for(auto &x: comp[j]){
                val = max(val,max_type[x]);
            }
            for(auto &x: comp[j]){ // assign this maxval for every component of this subgraph
                max_type[x] = val;
            }
        }
    }

    ll res = 0;

    for(int i=0;i <= mx;i++){
        res += (ll) max_type[i] *1LL* tp[i];
    }

    cout << res <<"\n";
	
}

signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
	#endif
    io;
    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}

