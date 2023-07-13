#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
    unordered_map<int, list<int>> l;
    public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    vector<int>  bfs(int src,int vertices){
        for(int i=1;i<= vertices;i++){
            if(l.find(i) == l.end())
                l[i].push_back(i);
        }

        vector<int> res;
        unordered_map<int, int> dist;
        for(auto &x: l){
            dist[x.first] = -1;
        }
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &x: l[node]){
                if(dist[x] == -1){
                    dist[x] = dist[node] + 6;
                    q.push(x);
                }
            }
        }

        for(int i=1;i<=vertices;i++)
            if(i != src)
                res.push_back(dist[i]);

        return res;
    }

};

void solve()
{
    int n,m;
    cin>>n>>m;
    Graph g;
    for(int i=0;i<m;i++){
        int v, u;
        cin>>v>>u;
        g.addEdge(v,u);
    }      
    int src;
    cin>>src;

    vector<int> distances = g.bfs(src,n); 
    for(auto &x: distances)
        cout<<x<<" ";
    cout<<endl;
}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int q;
    cin>>q;
    while(q--){
        solve();
    }

}
