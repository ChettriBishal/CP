#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string a,b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    int res=0;
    for(int i=1;i<=min(n,m);i++)
    {
        for(int j=0;j+i<=n;j++)
        {
            for(int k=0;k+i<=m;k++)
                if(a.substr(j,i)==b.substr(k,i))
                    res=max(res,i);
        }
    }
    cout<<n+m-2*res<<endl; // n-res+m-res
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;

}
/* consider abcd, bc we get LCS=bc */ // where LCS= longest common subsequence
