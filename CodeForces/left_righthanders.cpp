#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int j=n/2;
    for(int i=0;i<n/2;i++)
    {   
        if(s[i]=='R' and s[j]=='L') // only edge case we're supposed to handle
            cout<<j+1<<" "<<i+1<<"\n";
        else
            cout<<i+1<<" "<<j+1<<"\n";
        j++;
    }
    return 0;
    
}
