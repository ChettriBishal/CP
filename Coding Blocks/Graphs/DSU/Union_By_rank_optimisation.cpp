#include<iostream>
#include<list>
#include<utility>
#include<vector>
using namespace std;

class Graph{
    int V; // vertices
    list<pair<int,int>>l; // edge list
    public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int u, int v){
        l.push_back({u,v});
    }

    // find
    int findSet(int i, vector<int>& parent){
        if(parent[i] == -1) // base case 
            return i;
        return parent[i] = findSet(parent[i], parent); // path compression
    }

    // union by rank optimisation 
    void union_set(int x, int y,vector<int> & parent,vector<int>& rank){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

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

    bool contains_cycle(){
        // DSU logic to check if graph contains cycle or not
        vector<int> parent(V,-1); 
        vector<int> rank(V,1);

        // iterate over the edge list
        
        for(auto &edge: l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent); // find the super-parent / leader 
            int s2 = findSet(j, parent);

            if(s1 != s2){
                union_set(s1,s2,parent,rank);
            }
            else{
                cout<<"Same parents "<< s1 << " and "<< s2 <<endl;
                cout<<"For "<<i << " "<< j<< endl;
                return true;
            }
        }

        return false;
    }

};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0); // backedge 

    if(g.contains_cycle())
        cout<<"Graph contains cycle\n";
    else
        cout<<"No cycle present\n";

    return 0;

}
