#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// DSU data structure
// Path compression + Union by rank optimisation 
// MST: Minimum Spanning Tree

class DSU{
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        parent.resize(n,-1);
        rank.resize(n,1);
    }

    // find function

    int find(int i){
        // base case
        if(parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    // union
    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }

    }

};

struct edge{
    int x, y, w; // from x to y of weight w
};

bool weight_comp(edge& a, edge& b){
    return a.w < b.w; // sorting on the basis of weight 
}

class Graph{
    vector<edge> edgelist;
    int V;

    public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int x, int y,int w){
        edgelist.push_back({x,y,w});
    }

    int kruskal_mst(){
        // 1. Sort all the edges base upon weight 
        sort(edgelist.begin(), edgelist.end(),weight_comp);

        // initialise a DSU
        DSU s(V);

        int ans = 0;
        for(auto &e: edgelist){
            int w = e.w;
            int x = e.x;
            int y = e.y;

            // take edge in MST if it does not form a cycle 
            if(s.find(x) != s.find(y)){
                s.unite(x,y);
                ans += w; 
            }
        }

        return ans;
    }

};

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int n, m;
    cin >> n >> m;
    Graph g(n);

    while(m--){
        int x,y,w;
        cin >> x >> y >> w;
        g.addEdge(x-1,y-1,w); // in question its given as 1 based indexing 
    }

    cout << g.kruskal_mst() << endl;

    return 0;
}
