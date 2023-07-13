#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repi(k,i,n) for(int i=k;i<n;i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    bool en=true;
    int i=0,j=0,cnt=0;
    while(i<n and j<m)
    {   
        if(en){  // if in array a
            if(a[i]>b[j]){
                cnt++,j++;
                en=false;
            }
            else i++;
        }
        else{ // if in array b
            if(b[j]>a[i]){
                cnt++,i++;
                en=true;
            }    
            else j++;
        }
    }
    // if still in second array and imp moments in first array
    if(en==false and i<n) cnt++;
    // if still in first array and imp moments in second array
    else if(en==true and j<m) cnt++;
    cout<<cnt<<endl;
}
signed main()
{
	io;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
