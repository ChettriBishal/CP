#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int len=0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]) len+=2;
        else len++;
    }
    while(k--){
        int d;
        cin>>d;
        d--;
        s[d]=(s[d]=='0')?'1':'0';
        // left
        if(d>0){
            if(s[d-1]==s[d])
                len++;
            else
                len--;
        }
        // right
        if(d<n-1){
            if(s[d+1]==s[d])
                len++;
            else 
                len--;
        }
        cout<<len<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
