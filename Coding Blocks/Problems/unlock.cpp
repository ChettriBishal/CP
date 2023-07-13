#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    priority_queue<ll>b;
    for(ll &x:a){ 
        cin>>x;
        b.push(x);
    }
    if(k>n){ // if the no of swaps to be made is greater than the size of array then just sort it in descending manner
        sort(a.begin(),a.end(),greater<ll>() );
        for(auto k:a)
            cout<<k<<" ";
        return 0;
        
    }
    ll ind=0; // ind starting from first element 
    while(k--){
        if(b.empty()) 
            break;
        ll i=find(a.begin(),a.end(),b.top())-a.begin(); // the largest element so far
        if(i!=ind){ // if the indices are distinct then perform swapping
            swap(a[i],a[ind]);
        }
        if(i==ind) // if the same element was discovered then swapping doesn't take place 
            k++;
        b.pop();
        ind++;
    }
    for(auto k:a)
        cout<<k<<" "; 
    return 0;
    

}
