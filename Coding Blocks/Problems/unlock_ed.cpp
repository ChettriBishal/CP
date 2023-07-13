#include<bits/stdc++.h> // from the editorial
using namespace std;      // using map
typedef long long ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    unordered_map<int,int>ind; // to store the indices of elements
    ll i=0;
    for(ll &x:a){
        cin>>x;
        ind[x]=i++;
    }
    for(int i=0;i<n && k>0;i++)
    {
        ll val=n-i;
        if(a[i]==val) // already at correct place
            continue;
        // now swapping the index values of the map
        int temp=ind[val];
        ind[a[i]]=temp; // changing the position of current element 
        ind[val]=i; // changing the position of i_th greatest element
        swap(a[i],a[temp]); // actually swapping
        k--;
    }
    for(auto g:a)
        cout<<g<<" ";
    return 0;

}
