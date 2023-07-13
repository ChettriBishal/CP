#include<iostream>
#include<vector>
using namespace std;

// colors should alternate between 1 and 2 

bool dfs_helper(vector<int> graph[], int node, vector<int>& visited, int parent, int color)
{
    // come to node
    visited[node] = color; // color 1 or 2 both mean visited 
    
    for(auto &nbr: graph[node]){
        if(visited[nbr] == 0){ // if not visited 

            bool subprob = dfs_helper(graph, nbr, visited, node,  3 - color);

            if(subprob == false)
                return false;
        }

        else if(nbr != parent && color == visited[nbr])
            return false;
    }

    return true;

}

bool dfs(vector<int> graph[], int N)
{
    vector<int> visited(N, 0); // 0 --> not visited ; others --> colors 

    int color = 1;

    bool res = dfs_helper(graph, 0, visited,-1,color);

    // colors given to nodes
    for(int i=0; i< N ;i++)
        cout<<i << " - Color "<< visited[i]<<endl;

    return res;

}


int main()
{
    int N, M; // no of vertices and edges 
    cin>> N >> M;

    vector<int> graph[N]; 

    while(M--){
        int x, y;
        cin>> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);

    }

    // BFS or DFS
    // By coloring the nodes at each step 
    // current node has color 1, nbr should have color 2

    if(dfs(graph, N)){
        cout<<"Graph is bipartite \n";
    }
    else
        cout<<"Graph is not bipartite\n";

    return 0;

}
/*
5 4
0 1 
0 2
1 3 
2 4
*/
