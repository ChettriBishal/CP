// counting sort implementation
#include<bits/stdc++.h>
using namespace std;
 
 
void solve()
{
    int n;cin>>n;
    int freq[n+1]; 
    memset(freq,0,sizeof(freq));
 
    for(int i=1;i<=n;i++){
        string s; // of no use
        cin>>s;
        int val;
        cin>>val;
        freq[val]++;
    }
    
    long long int res = 0;
    int j = 1, i = 1; // index for the freq array
   
    while(i<=n){
        if(freq[j]>0){
            res += abs(i - j);
            freq[j]--;
            i++;
        }
        else j++;
    }
 
    cout<<res<<endl;
}
 
int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 
