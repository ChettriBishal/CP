#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V; // no of vertices
    list<int> *l;
    public: 
    Graph(int Vertices){
        V = Vertices;
        l = new list<int> [V]; // array of linked lists
    }

    void AddEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void Print(){
        for(int i=0;i<V;i++){
            cout<<"Vertex "<<i<<" --> ";
            for(auto & el: l[i]){
                cout<<el<<" ";
            }
            cout<<endl;
        }
    }

};



int main()
{

    Graph g(4); // creating a graph with four vertices
    // here the edges are bi-directional
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(2,1);
    g.AddEdge(2,3);

    g.Print();

    return 0;

}
