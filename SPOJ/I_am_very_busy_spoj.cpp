// Activity selection algorithm GREEDY
#include<bits/stdc++.h>
using namespace std;

// compare on the basis of end time
bool method(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

void solve()
{
    vector<pair<int,int>> time;
    int n;
    cin>>n;

    for(int i= 0;i<n;i++){
        int s, e; // start and end time of each activity
        cin>>s>>e;
        time.push_back({s,e});
    }   
   
    sort(time.begin(),time.end(),method);
   
    int cnt = 1; // cause the first activity is always taken
    int prev = time[0].second; 
    
    for(int i =1;i<n;i++){
        if(time[i].first >= prev){
            cnt++;
            prev = time[i].second;
        }
    }
    
    cout<<cnt<<endl;

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
