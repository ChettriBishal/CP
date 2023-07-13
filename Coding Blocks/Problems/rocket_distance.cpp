#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    priority_queue<ll>rd; // to store the rocket distance
    int q,k;
    cin>>q>>k;
    while(q--){
        int t;
        cin>>t;
        if(t==2){
            cout<<rd.top()<<"\n";  // top of queue will always contain the kth smallest item 
        }
        else{
            ll x,y;
            cin>>x>>y;
            rd.push(x*x + y*y);
            while((int)rd.size()>k) // if the size is greater than k then keep popping
                rd.pop();
        }
    }
    return 0;
}
