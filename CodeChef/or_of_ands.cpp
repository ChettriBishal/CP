/* Bishal
21-Apr-21 10:54:27 PM
*/
#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n),bits(31,0);
    for(int &x:a){
        cin>>x;
        for(int i=0;i<31;i++){  
            if(x & (1<<i)) // or even (x>>i)&1 would do
                bits[i]++;
        }
    }
    ll res=0;
    for(int i=0;i<31;i++)
        res+=(1<<i)*(bits[i]>0); // if there is a set bit then it will contribute 
    cout<<res<<"\n";
    for(int j=0;j<q;j++)
    {
        res=0;
        int ind; ll val;
        cin>>ind>>val;
        ind--;
        for(int i=0;i<31;i++) // removing the contribution of a[ind] from res  
            if(a[ind] &(1<<i))
                bits[i]--;
        a[ind]=val;
        for(int i=0;i<31;i++) // add the contribution of new value entered
            if(val&(1<<i)) 
                bits[i]++;
        for(int i=0;i<31;i++)
            res+=(1<<i)*(bits[i]>0);
        cout<<res<<"\n";
    }
}
int main()
{
    io;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
