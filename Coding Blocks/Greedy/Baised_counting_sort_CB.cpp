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
   
    int actual_rank = 1;
    
    for(int i= 1;i<=n;i++){
        while(freq[i]){
            res += abs(i - actual_rank);
            freq[i]--;
            actual_rank++;
        }
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
