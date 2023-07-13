#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a[1000][1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int cnt=0;
            if(j+1<=n)
                if(a[i][j+1]=='o') cnt++;
            if(i+1<=n)
                if(a[i+1][j]=='o') cnt++;
            if(i-1>=0)
                if(a[i-1][j]=='o') cnt++;
            if(j-1>=0)
                if(a[i][j-1]=='o') cnt++;
           // cout<<i<<" "<<j<<" "<<"count="<<cnt<<endl;
            if(cnt%2!=0)
            {
                flag=false;
                break;
            }
        }
        if(flag==false)
            break;
    }
   // cout<<endl;
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
