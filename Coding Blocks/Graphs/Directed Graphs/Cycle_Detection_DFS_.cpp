#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph{
    list<int> *l;
    int V; // no of vertices
    public:

    Graph(int V){
        this->V = V;
        l = new list<int>[V]; // array of lists 
    }

    void addEdge(int x, int y){
        // directed graph
        l[x].push_back(y);
    }

    bool cycle_helper(int node, vector<bool> & visited, vector<bool>& curr_path){

        // when you visit a node
        visited[node] = true; 
        curr_path[node] = true; // is part of the current path

        for(int &nbr: l[node]){
            // two cases
            if(curr_path[nbr] == true) // backedge
                return true;

            else if(visited[nbr] == false){ // not visited --> make dfs call on it 
                bool found = cycle_helper(nbr, visited, curr_path);
                if(found == true)
                    return true;
            }

        }

        // when you leave a node
        curr_path[node] = false; // no longer a part of the current path

        return false; // no cycle present 

    }


    bool contains_cycle(){
        // check for cycle in directed graph

        vector<bool> visited(V,false);
        vector<bool> curr_path(V,false); // nodes present in the current path

        return cycle_helper(0,visited, curr_path);
    }

};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(1,5);

    g.addEdge(4,2); // backedge 

    if(g.contains_cycle())
        cout<<"Graph contains cycle\n";
    else
        cout<<"No cycle present\n";

    return 0;
}
