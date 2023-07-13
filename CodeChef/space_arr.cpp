/*bishal
11-Apr-21 7:12:21 PM
*/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &x:a)
        cin>>x;
    sort(a.begin(),a.end());
    int cnt=0; // no of moves
    bool en=true; // chance for first player to win
    for(int i=0;i<n;i++){
        if(a[i]>i+1){
            en=false;
            break;
        }
        cnt+=(a[i]-i-1);
    }
    if(en){
        if(cnt&1) cout<<"First\n"; // if the number of moves is odd 
        else goto k; // if even then the second player wins
    }
    else{
        k:
        cout<<"Second\n";
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
