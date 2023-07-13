#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    // adjacency list implementation 
    vector<pair<int,int>> *l; // l[0] --> {(1,3)}, {(2,4)}, .. 
    int V;
    public:
    Graph(int n){
        V = n;
        l = new vector<pair<int,int>>[n]; // every block contains the neighbour and weight 
    }
    void addEdge(int x, int y, int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }

    int Prim_mst(){
        // init a min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> Q;

        // visited array to check if the node has been included in MST set
        vector<bool> visited(V,false);

        int ans = 0;
        // begin
        Q.push({0,0});// weight-value; opposite to that of adjacency list 

        // Q will take the first pair in comparison

        while(!Q.empty()){
            // pick out the edge with minimum weight 
            auto best = Q.top();
            Q.pop();

            int to = best.second; // directed to 
            int weight = best.first;
            if(visited[to] == true){
                // discard the edge and continue
                continue;
            }
            // else take the current edge 
            ans += weight;
            visited[to] = true;
            
            // add the new edges in the queue 
            for(auto &x: l[to]){
                if(visited[x.first] == false){
                    Q.push({x.second, x.first});
                }
            }
        }

        return ans;
    }
    
};

int main()
{
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(0,2,2);
    g.addEdge(0,3,2);
    g.addEdge(1,3,2);
    g.addEdge(1,2,2);
    g.addEdge(2,3,3);

    cout << "The minimum spanning tree in the graph has cost of " << g.Prim_mst() << endl;

    return 0;
}
