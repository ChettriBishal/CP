#include<iostream>
#include<list>
#include<cstring>
#include<queue>

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

    void topological_sort(){
        // indegree
        int indegree[V];
        memset(indegree,0,sizeof(indegree));
        
        // update indegree by traversing edges

        for(int i=0;i < V;i++){
            for(auto& y: l[i]){
                indegree[y]++;
            }
        }

        // bfs
        // find nodes with indegree = 0

        queue<int> q;
        for(int i=0;i < V;i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty()){
            int curr = q.front();
            cout<< curr<< " ";
            q.pop();
            // iterate over the neighbours and reduce their indegree
            for(auto &nbr: l[curr]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

    }

};

int main()
{
    Graph g(6);

    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,5);

    /*
     Graph looks like this
     0     1 
     |   / |
     |  /  |
     | /   |
     2     4
     | \   |
     |  \  |
     |   \ |
     3-----5
     
      */

    g.topological_sort();

    return 0;
}
