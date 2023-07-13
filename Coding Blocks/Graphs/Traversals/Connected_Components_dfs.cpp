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

        visited[src] = true;

        cout<<src<<" ";
        for(T & nbr: l[src]){
            if(!visited[nbr]){ // if not visited
                dfs_helper(nbr,visited);
            }
        }

    }
    void dfs(){
        unordered_map<T, bool> visited;

        for(auto & node: l){
            visited[node.first] = false;
        }

        // iterate over all vertices and initialise dfs calls
        int cnt = 0;
        for(auto &p: l){
            if(!visited[p.first]){
                cout<<"Component "<< cnt<<" --> ";
                dfs_helper(p.first,visited); // number of dfs calls made will be equal to the number of vertices
                cnt++;
                cout<<endl;
            }
        }

    }

};


int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.addEdge(5,6);
    g.addEdge(6,7);

    g.addEdge(8,8);
    
    g.dfs();

    return 0;

}
