#include<iostream>
#include<map>
#include<unordered_map>
#include<queue>
#include<list>
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
        unordered_map<T, bool> visited; 
        queue<T> sofar;

        sofar.push(src);

        while(!sofar.empty()){
            T node = sofar.front();
            cout<<node<<endl;
            sofar.pop();
            visited[node] = true; // visited
            for(auto &nbr: l[node]){
                if(visited[nbr] == false){
                    sofar.push(nbr);
                    visited[nbr] = true;
                }
            }
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

