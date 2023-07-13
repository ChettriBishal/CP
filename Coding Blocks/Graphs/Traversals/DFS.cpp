#include<iostream>
#include<map>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> l;
    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(T src, unordered_map<T,bool> & visited){
        // recursive function
        visited[src] = true;

        cout<<src<<" ";
        for(T & nbr: l[src]){
            if(!visited[nbr]){ // if not visited
                dfs_helper(nbr,visited);
            }
        }

    }
    void dfs(T src){
        unordered_map<T, bool> visited;
        for(T & nbr: l[src]){
            visited[nbr] = false;
        }

        dfs_helper(src,visited);

        cout<<endl;

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
    
    g.dfs(0);

    return 0;

}

