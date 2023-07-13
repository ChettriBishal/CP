#include<iostream>
#include<list>
#include<unordered_map>
#include<utility>
#include<climits>
#include<set>
#include<queue>

using namespace std;

template<typename T>

class Graph{
    unordered_map<T, list<pair<T,int>>> m;
public:
    void addEdge(T u, T v,int dist, bool bidir = true){
        m[u].push_back({v,dist});
        if(bidir)
            m[v].push_back({u,dist});
        
    }

    void printAdj(){
        // printing the adjacency list
        for(auto& adj: m){
            cout << adj.first <<"---> ";

            for(auto &p: adj.second){
                cout <<"("<<p.first <<", "<<p.second <<")";
            }
            cout << endl;
        }

    }

    void dijkstraS(T src){
        unordered_map<T,int> dist;

        for(auto& j: m) // initially set all distance to infinity
            dist[j.first] = INT_MAX;

        // Make a set to find out a node with the minimum distance 
       
        set<pair<int,T>> s; // distance - node; thus will be sorted as per distance  

        dist[src] = 0;
        s.insert({0,src}); // first pushing the source node

        while(!s.empty()){
            // Find the pair at the front 
            // Pair at front will be the one with minimum distance 
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            // iterate over neighbours/children of the current node
            for(auto &nbr: m[node]){
                if(nodeDist + nbr.second < dist[nbr.first]){
                    // In set updation of particular node is not possible
                    // we need to remove the old pair and insert the new pair to simulate updation 

                    T dest = nbr.first; // node we are going to 
                    auto f = s.find({dist[dest],dest});

                    if(f != s.end()){
                        s.erase(f);
                    }
                    // insert the new pair 
                    dist[dest] = nodeDist + nbr.second;
                    s.insert({dist[dest],dest});
                }
            }
        }
        // print distances from source to all other nodes 
        for(auto &d: dist)
            cout<<d.first <<" is located at distance of " << d.second <<endl;
        
    }

};

int main()
{
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(1,4,7);
    g.addEdge(3,4,2);
    g.addEdge(2,3,1);

    g.printAdj();

    g.dijkstraS(1);

    return 0;

}
