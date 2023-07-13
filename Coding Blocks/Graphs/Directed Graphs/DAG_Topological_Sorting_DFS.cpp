#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> l;
    public:

    void addEdge(T x, T y){
        l[x].push_back(y); // directed graph 
    }

    void dfs_helper(T src, unordered_map<T,bool> & visited, list<T> & ordering){

        visited[src] = true;

        for(T & nbr: l[src]){
            if(!visited[nbr]){ // if not visited
                dfs_helper(nbr,visited, ordering);
            }
        }

        ordering.push_front(src); // pushing the node
    }

    void dfs(){
        unordered_map<T, bool> visited;

        list<T> ordering;

        for(auto & node: l){
            visited[node.first] = false;
        }

        for(auto &p: l){
            if(!visited[p.first]){
                dfs_helper(p.first,visited, ordering); 
            }
        }
        // finally print the list

        for(auto &el: ordering)
            cout<<el <<  " ";
        cout<<endl;
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);

    /*
     Graph looks like this:
             0
           *  *
          *    *
         1      2
          *    *
           *  *
             3

    Topological sorting: 0 1 2 3

    */

    g.dfs();

    return 0;

}
