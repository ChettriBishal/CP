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


constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

template<typename T>
class Graph{
    unordered_map<int,list<pair<T,int>>> m;
    public:
    void addE(T u, T v,int timereq){
        m[u].push_back({v,timereq});
        m[v].push_back({u,timereq});
    }

    unordered_map<T,int> timereq;

    void dijkstras(T src){

        for(auto &x: m){
            timereq[x.first] = INT_MAX;
        }

        set<pair<int,T>> s; // set atomatically sorts on the basis of timereq

        timereq[src] = 0;

        s.insert({0,src});

        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            
            int nodeDist = p.first;
            s.erase(s.begin());

            // iterate over the neighbours of the current node 
            for(auto &nbr: m[node]){
                if(nodeDist + nbr.second < timereq[nbr.first]){

                    T dest = nbr.first; // node we are going towards 
                    auto f = s.find({timereq[dest],dest});

                    if(f != s.end()) s.erase(f);

                    // insert the new pair
                    timereq[dest] = nodeDist + nbr.second;
                    s.insert({timereq[dest],dest});
                }
            }

        }

    }

};

void solve()
{
    int n,m,r,x,y;
    cin >> n >> m >> r >> x >> y;
    Graph<int> g;

    for(int i=0;i < r;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g.addE(u,v,w);
    }

    g.dijkstras(x);

    int availb = g.timereq[y]; // shortest time taken to reach y from x

    if(availb <= m)
        cout << "alive " <<availb<<endl;
    else
        cout <<"died\n";
	
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

