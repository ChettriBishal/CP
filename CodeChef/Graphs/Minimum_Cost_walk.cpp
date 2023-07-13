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

#define ALL_THE(Cake,Lie) for(auto Lie = Cake.begin(); Lie!= Cake.end(); Lie++)

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

class Graph{
    unordered_map<ll,list<pair<ll,ll>>> edges;
    ll m = 0; // max node
    public:
    void addEdge(ll a, ll b, ll c){
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
        m = max({m,a,b});
    }

    unordered_map<ll,ll> cost;

    void dijkstras(ll src){
        cost.clear();
        for(ll i=1;i <= m;i++){
            cost[i] = INF;
        }
        
        set<pair<ll,ll>> st;
        cost[src] = 0;
        st.insert({0,src});
        
        while(!st.empty()){
            ll node = st.begin()->second;
            ll nodeDist = st.begin()->first;
            st.erase(st.begin());

            for(auto &nbr: edges[node]){
                if(nbr.s + nodeDist < cost[nbr.f]){
                    auto f = st.find({cost[nbr.f],nbr.f});
                    if(f != st.end()) st.erase(f);

                    cost[nbr.f]= nbr.second + nodeDist;
                    st.insert({cost[nbr.f],nbr.f});
                }
            }
        }
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll S, T, V;
    cin >> S >> T >> V;

    Graph g;

    for(int i=0;i < m;i++){
        ll a, b, w;
        cin >> a >> b >> w;
        g.addEdge(a,b,w);
    }

    unordered_map<ll,ll> D_s , D_t, D_v;
    
    g.dijkstras(S);
    D_s = g.cost;

    g.dijkstras(T);
    D_t = g.cost;

    g.dijkstras(V);
    D_v = g.cost;

    ll res = INF;

    for(int i=1;i <= n;i++){
        res = min(res, D_s[i] + D_t[i] + D_v[i]);
    }

    cout << res  <<"\n";
	
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

