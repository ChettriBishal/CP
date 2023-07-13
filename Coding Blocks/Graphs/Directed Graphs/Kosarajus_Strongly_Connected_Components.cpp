/* Strongly Connected Components: Kosaraju's Algorithm*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;


void dfs(int node, vector<int> graph[], vector<bool>& visited, stack<int>& ordering){
    visited[node] = true;

    for(auto &nbr: graph[node]){
        if(visited[nbr] == false){
            dfs(nbr, graph, visited, ordering);
        }
    }

    // going back from that node
    ordering.push(node);

}


void dfs2(int node, vector<int> graph[], vector<bool>& visited){
    visited[node] = true;

    cout<< node <<" ";
    for(auto &nbr: graph[node]){
        if(visited[nbr] == false){
            dfs2(nbr, graph, visited);
        }
    }

}

void kosaraju(vector<int> graph[], vector<int> rev_graph[],int V){

    vector<bool> visited(V, false);

    stack<int> ordering;
    
    // step 1: Store the vertices according to their dfs finish time
    for(int i=0;i < V;i++){
        if(visited[i] == false){
            dfs(i, graph, visited,ordering);
        }
    }

    // step 2: Reverse the graph and store as copy (already done here)
    // step 3: Perform DFS over elements according to the ordering from top of the stack

    fill(visited.begin(), visited.end(), false); // reset the visited vector

    char component_name = 'A';

    while(! ordering.empty()){
        int node = ordering.top(); 
        ordering.pop();
        if(! visited[node]){
            cout<<"Component "<< component_name << "---> ";
            // there is a component starting from this node 
            dfs2(node, rev_graph, visited);
            component_name ++;
            cout<<endl;
        }
    }

}


int main()
{
    freopen("input.txt","r",stdin);
    int V;
    cin >> V;  // no of vertices 
    vector<int> graph[V];
    vector<int> rev_graph[V];

    int m; // edges
    cin >> m;

    while(m--){
        int x, y;
        cin>> x >> y;
        graph[x].push_back(y); // directed graph 

        rev_graph[y].push_back(x);
    }

    kosaraju(graph, rev_graph, V);

    return 0;
}

/*
input.txt

7
8
1 0
0 2
2 1
0 3
3 5
5 6
6 3
3 4

*/
