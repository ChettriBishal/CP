#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>

using namespace std;

template<typename T> 
class Graph{
    int V; // vertices

    unordered_map<T,list<T> > l;

    public:

    Graph(int v){
        V = v;
    }

    void addEdge(T x, T y, bool directed = false){ // undirected graph
        l[x].push_back(y);

        if(! directed)
            l[y].push_back(x);
    }

    bool cycle_helper(T node, vector<bool>& visited, T parent) // parent = parent of current node
    {
        visited[node] = true;

        for(auto& nbr: l[node]){
            if(! visited[nbr]){ // recursively visit the neighbour
                bool cycle_there = cycle_helper(nbr,visited, node);
                if(cycle_there)
                    return true;
            }
            // nbr is already visited by isn't equal to the parent 
            else if(nbr != parent){
                return true;
            }
        }

        return false;

    }

    bool contains_cycle(){

        vector<bool> visited(V, false);

        return cycle_helper(0, visited, -1);
    }

};

int main()
{
    Graph<int> g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0); // reason for the cycle ... uncomment to see what happens
    
    if(g.contains_cycle())
        cout<<"Yes, there is cycle in the undirected graph\n";
    else
        cout<<"No cycle present!\n";

    return 0;

}
