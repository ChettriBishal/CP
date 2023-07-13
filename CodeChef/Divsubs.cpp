#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve()
{
    int n;
    cin>>n;
    vector<ll>a(n);
    for(ll &x:a)
        cin>>x;
    vector<ll> pre(n+1); // creating prefix sum array
    pre[0]=0;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i-1];
    for(int i=0;i<=n;i++)
        pre[i]=((pre[i]%n)+n)%n;
    map<ll,ll>res;
    for(int i=0;i<=n;i++){
        res[pre[i]]++;
    }
    int start=0,end=0;
    for(auto k:res){
        if(k.s>1){ // if one hole adjusts more than one pigeon
            for(int i=0;i<=n;i++){
                if(pre[i]==k.f){
                    start=i;
                    break;
                }
            }
            for(int i=n;i>=0;i--){
                if(pre[i]==k.f){
                    end=i;
                    break;
                }
            }
            break;
        }
    }
    cout<<end-start<<"\n";  // end-start =length of the subarray
    for(int i=start;i<end;i++) //it's not <=end because it's already one step ahead of array a 
        cout<<i+1<<" ";         // also the array we're given is in 0 based indexing and not 1 based
    cout<<"\n";
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
/*
 * Explantion for the <end part
 * Consider this input:
 * 1
 * 5
 * 1 2 5 2 2
 *
 * a:     0   1   2   3   4 --->index
 *        1   2   5   2   2
 *
 * pre:    0   1   2   3   4 --->index
          
           0   1   3   8   10  12 
 * for pre 
 * start =0 , end=4 (pre[4]=10)
 * for a
 * start =0, end=3 (a[0]+a[1]+a[2]+a[3]=10)
 *
*/
