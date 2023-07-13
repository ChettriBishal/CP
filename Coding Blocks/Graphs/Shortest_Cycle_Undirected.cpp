#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

void bfs(vector<int> graph[] , int src, int n, int & ans)
{
    vector<int> dis(n +1, INT_MAX); // to store the distance 
    queue<int> q;
    
    q.push(src);

    dis[src] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int &nbr: graph[curr]){
            if(dis[nbr] == INT_MAX){ // not visited 
                dis[nbr] = dis[curr] + 1;
                q.push(nbr);
            }
            else if(dis[nbr] >= dis[curr]){ // backedge is encountered 
                ans = min(ans, dis[nbr] + dis[curr] + 1);
            }
        }
    }

}


int main()
{
    freopen("input.txt","r",stdin);
    int n, m;

    cin>> n >> m; // no of vertices and edges

    vector<int> graph[n + 1];

    for(int i=0; i < m;i++){
        int x, y;
        cin>>x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ans = n + 1;

    for(int i=1; i<= n;i++){
        bfs(graph, i, n, ans);
    }

    if(ans == n + 1){
        cout<<"No cycle present in the graph\n";
    }
    else{
        cout<<"The shortest cycle present in the graph is " << ans << endl;
    }

}
