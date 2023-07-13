#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
typedef long long ll;

template<typename T>
class Graph{
    unordered_map<T, list<T>> l;
    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    vector<int> bfs()
    {
        unordered_map<T,bool> visited;
        for(auto & v:l ){
            for(auto &x: l[v.first])
                visited[x] = false;
        }

        vector<int> res; // the store the number of elements in every component
        //int bis = 0;
        for(auto &p: l){
            queue<T> q;
            q.push(p.first);
            if(visited[p.first] == true){
                q.pop();
                continue;
            }
            visited[p.first] = true;
            //cout<<"Component "<<bis++<<" --> ";

            int cnt = 0;
            while(!q.empty()){
                cnt++;
                T node = q.front();
                //cout<<node<<" ";
                q.pop();
                for(auto &nbr: l[node]){
                    if(!visited[nbr]){
                        //cnt++;
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            res.push_back(cnt);
            //cout<<endl;
        }
        return res;
    }
};

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    Graph<int> g;
    int n,p;
    cin>>n>>p;
    for(int i=0;i<p;i++){
        int a, b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    vector<int> ccs =  g.bfs(); // ccs size of every connected component
    ll tot = n *1LL* (n-1)/2ll; // total no of combinations (two at a time)
    for(auto &k: ccs){
        tot -= (k * (k-1))/2; // deducting the ones which are common --> same country 
    }
    cout<<tot<<endl;

    return 0;

}
