#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// here we will use the edge list representation 

vector<int> bellman_ford(int v, int src, vector<vector<int>>& edges){

    // create a vector
    vector<int> dist(v+1, INT_MAX);
    dist[src] = 0;

    // relax all edges v-1 times 

    for(int i=0;i < v-1;i++){
        for(auto &edge: edges){
            int u = edge[0]; // from 
            int v = edge[1]; // to
            int wt = edge[2]; // weight of edge

            if(dist[u] != INT_MAX and dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }

        }
    }
    
    // to check for negative weight cycle 
    // if there is no negative weight cycle then the values of distances can't be changed anymore 
    
    for(auto &edge: edges){
        int u = edge[0]; // from 
        int v = edge[1]; // to
        int wt = edge[2]; // weight of edge
        if(dist[u] + wt < dist[v]){
            cout << "Negative weight cycle found\n";
            exit(0);
        }
    }

    return dist;
}



int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int n, m; // n vertices and m edges 
    cin >> n >> m;
    // edge list 
    vector<vector<int>> edges; // (a,b,3) -->(from, to, weight)

    for(int i=0;i < m;i++){
        int u , v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
    }
    
    // bellman ford algorithm 

    vector<int> distances = bellman_ford(n, 1,edges);

    for(int i=1; i<=n;i++)
        cout << "Node " << i << " is at distance "<<distances[i]<<endl;


    return 0;
}

/*

This is will contain negative weight cycle 
3 3
1 2 3
2 3 4
3 1 -10


3 3
1 2 3
2 3 4
1 3 -10 // just reversing this edge

Node 1 is at distance 0
Node 2 is at distance 3
Node 3 is at distance -10

*/
