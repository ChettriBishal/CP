#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int>pq_max; // max heap
    for(int i=1;i<=9;i++)
        pq_max.push(i); // O(logN)
    
    cout<<"Elements of priority queue (max heap)\n";
    while(!pq_max.empty())
    {
        cout<<pq_max.top()<<" ";
        pq_max.pop();
    }
    cout<<endl;
    priority_queue<int,vector<int>,greater<int>> pq_min; // min heap
    for(int i=1;i<=9;i++)
        pq_min.push(i);
    cout<<"Elements of priority queue (min heap)\n";
    while(!pq_min.empty())
    {
        cout<<pq_min.top()<<" ";
        pq_min.pop();
    }
    cout<<endl;
    return 0;


}
