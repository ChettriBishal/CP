#include<bits/stdc++.h>
using namespace std;
 
bool comp(pair<string,int> a, pair<string,int> b){
    return a.second < b.second;
}
 
void solve()
{
    int n;
    cin>>n;
    vector<pair<string,int>> teams;
 
    for(int i=0;i<n;i++){
        string s; int val;
        cin>>s>>val;
        teams.push_back({s,val});
    }
 
    sort(teams.begin(),teams.end(),comp);
 
    long long res = 0;
    for(int i= 0 ;i<n;i++){
        res += abs(teams[i].second-i-1);
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
 
