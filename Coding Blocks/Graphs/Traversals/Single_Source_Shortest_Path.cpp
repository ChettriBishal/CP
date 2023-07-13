#include<iostream>
#include<map>
#include<unordered_map>
#include<queue>
#include<list>
#include<climits>
using namespace std;

template<typename T> 
class Graph{
    map<T,list<T> > l;
    public:
    void addEdge(T x, T y){ // undirected graph
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        unordered_map<T,int> dist;
        queue<T> q;
        
        for(auto node: l){
                dist[node.first] = INT_MAX;
        }

        dist[src] = 0; // distance of source node from itself 

        q.push(src);
        while(!q.empty()){
            // marking the distance of its neighbours
            T curr = q.front();
            q.pop();
            for(auto & nbr: l[curr] ){
                if(dist[nbr] == INT_MAX){ // visiting that node for first time
                    dist[nbr] = dist[curr]+ 1; // updating the distance of the current node
                    q.push(nbr);
                }
            }
        }

        for(auto k: l){
            cout<<"Distance of node "<<k.first<<" from source node "<<src<<" is "<<dist[k.first]<<endl;
        }
    }

};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    
    g.bfs(0);

    return 0;

}

