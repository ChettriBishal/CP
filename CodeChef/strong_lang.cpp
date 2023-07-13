#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool en=false;
    for(int i=0;i<n;i++)
    {
        int check=0;
        bool in=false;
        while(s[i]=='*'){ 
            check++;
            i++;
            in=true;
        }
        if(check>=k){
            en=true;
            break;
        }
        if(in) i--; // if i's value is updated then neutralisation sort of
    }
    string res=en?"YES\n":"NO\n";
    cout<<res<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
