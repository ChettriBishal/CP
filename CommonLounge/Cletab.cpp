#include<bits/stdc++.h>
using namespace std;
const int N=1000;
vector<bool>in(N,false); // is in the table
vector<int>a(N),rec(N),seen(N,0);
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        rec[a[i]]=i; // most recent pos 
    }
    // now enter the first customers till the table is full
    fill(in.begin(),in.end(),false); 
    fill(seen.begin(),seen.end(),0); // this filling is important in online judge
    int j=0; // say this is the order number 
    int cnt=0; 
    while(j<m and (cnt<n or in[a[j]]))
    {
        if(!in[a[j]]){
            cnt++;
            in[a[j]]=true;
        }
        j++;
    }
    while(j<m)
    {
        if(!in[a[j]])
        {
            int victim=-1;
            for(int i=j-1;i>=0;i--)
            {
                if(in[a[i]] and rec[a[i]]==i){ //cause if customer doesn't come again then his order no is stagnant
                    victim=a[i];
                    break;
                }
            }
            if(victim==-1){ // if all the available future customers are from the tables
                for(int i=j+1;i<m;i++){
                    if(in[a[i]] and seen[a[i]]!=j){
                        victim=a[i];
                        seen[a[i]]=j; // updating the value of seen so if we have like  1 4 4 4 8 then we won't remove 4 
                    }
                }
            }
            in[victim]=false; // removing that person from the tables
            cnt++;
            in[a[j]]=true; // adding another person in
        }
        j++;
    }
    cout<<cnt<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
