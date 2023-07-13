#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
struct Compare
{
    bool operator()(pi const & a, pi const & b)
    {
         if(a.second < b.second)
         {
            return true;
         }
         else if(a.second > b.second)
         {
             return false;
         }
         else
         {
             if(a.first > b.first)
             {
                 return true;
             }
             return false;
         }
    }
};
int main()
{
    priority_queue<pi , vector<pi>, Compare>q;
    q.push({1, 5});
    q.push({5, 15});
    q.push({7, 15});
    q.push({10, 2});
    q.push({1, 10});
    cout<<"Queue\n";
    cout<<"Priority increases as we move up\n";
    int n=4;
    while(!q.empty())
    {
        cout<<q.top().first<<"  "<< q.top().second<<" ^\n";
        q.pop();
    }
    return 0;
}

/*
Output:

Queue
Priority increases as we move up
5  15 ^
7  15 ^
1  10 ^
1  5 ^
10  2 ^

*/
