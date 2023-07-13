/* to sum any two numbers from the set given you need to choose two numbers 
 * ...such that when you look at any decimal place of either of the two numbers
 * ...atleast one of the two numbers will have zero at that decimal place
 */

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>cnt(5,0);
    for(int i=0;i<n;i++)
    {   
        int d;
        cin>>d;
        if(d==0){   
            cnt[0]=1;
            continue;
        }
        if(d==100){ 
            cnt[1]=1;
            continue;
        }
        if(d%10==0){ // say case 2
            cnt[2]=d;
            continue;
        }
        if(d<10){ // say case 3  
            cnt[3]=d;
            continue;
        }
        cnt[4]=d; // for the fourth case
    }
    vector<int>res;
    if(cnt[0]) res.pb(0);
    if(cnt[1]) res.pb(100);
    if(cnt[2]) res.pb(cnt[2]);
    if(cnt[3]) res.pb(cnt[3]);
    if(cnt[4] and !cnt[2] and !cnt[3]) res.pb(cnt[4]);
    cout<<res.size()<<"\n";
    for(auto k:res)
        cout<<k<<" ";
    return 0;
}
