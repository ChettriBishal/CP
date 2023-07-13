#include<iostream>
#include<list>
#include<unordered_map>
#include<string>
using namespace std;

class Graph{
    unordered_map<string, list<pair<string,int>>> l; 

    public:
    void AddEdge(string x, string y, bool bidirectional, int wt)
    {
        l[x].push_back({y, wt});
        if(bidirectional){ 
            l[y].push_back({x,wt});
        }
    }

    void Print(){
        for(auto &item: l){
            string city = item.first; 
            list<pair<string, int>> neighbours = item.second; // neighbours of the city
            cout<<city<<" --> ";
            for(auto &nbr: neighbours){
                string dest = nbr.first;
                int dist = nbr.second;
                cout<<"( "<<dest<<","<<dist<<" )";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g;
    g.AddEdge("A","B",true,20);
    g.AddEdge("A","C",true,10);
    g.AddEdge("C","D",true,40);
    g.AddEdge("D","B",true,30);
    g.AddEdge("A","D",false,50);

    g.Print();

    return 0;


}
