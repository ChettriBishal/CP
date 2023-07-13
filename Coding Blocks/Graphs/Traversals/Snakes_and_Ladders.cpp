// Mon Oct 11 21:59:41 2021
// Check the picture for better visualization 
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
    void addEdge(T x, T y){ // directed graph
        l[x].push_back(y);
    }

    void bfs(T src, T dest)
    {
        unordered_map<T, int > dist; 
        unordered_map<T,T> parent; // to store the parent of every node
        queue<T> q;

        for(auto k: l){
            dist[k.first] = INT_MAX;
        }

        dist[src] = 0;
        parent[src] = src; // parent of source is source itself
        q.push(src);

        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto &nbr: l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }
        
        //cout<<"Shortest Distance from \n";
        //for(auto k: l){
            //cout<<src<<" to dest "<<k.first<<" is "<<dist[k.first]<<endl;
        //}

        T temp = dest;

        cout<<"ANS = "<<dist[dest]<<endl;

        cout<<"\nDestination to source\n";

        while(temp != src){
            cout<<temp<<" <--";
            temp = parent[temp];
        }
        cout<<src<<endl;

        
    }

};


int main()
{
    int board[50] = {0}; // board to store the jumps 
    // a jump can be positive ---> through ladder
    // or it can even be negative ---> through snake
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;

    // Add all edges to the graph
    for(int i=0;i <= 36;i++){ // there are 36 nodes in the graph 
        for(int dice = 1; dice <=6; dice++){ // every dice throw has 6 possibilities
            int j = i + dice; // next throw from current state 
            j += board[j]; // the jump
            if(j <= 36){ // due to the jump the value might be alteast 37 so we handle 36 outside this loop
                g.addEdge(i,j);
            }

        }
    }

    g.addEdge(36,36);

    g.bfs(0,36); // shortest path from source to destination 
 
}
