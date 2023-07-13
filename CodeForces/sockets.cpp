/*
13-Apr-21 11:17:43 AM
*/
#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n);
    for(int &x:a)
        cin>>x;
    sort(a.begin(),a.end(),greater<int>());
    int j=0, plugs=k;// j-->number of supply line filters
    while(j<n and plugs<m)//while the plugs available is less than the number of devices
    {
        plugs+=a[j]-1; // -1 cause the plug is occupied by a filter having a[j] sockets
        j++;
    }
    if(plugs>=m) 
        cout<<j<<endl;
    else // if no of plugs is still less than the number of devices
        cout<<-1<<endl;
    return 0;
}
