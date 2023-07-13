#include<iostream>
using namespace std;
int main()
{
    int a[101],n,c,prof=0,val;
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            val=a[i-1]-a[i]-c;
           // cout<<i<<" "<<val<<" ";
            if(val>prof) prof=val;
        }
    }
    cout<<prof<<endl;
    return 0;
}