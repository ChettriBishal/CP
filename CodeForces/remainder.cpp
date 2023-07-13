#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &val:a) // taking input into vector a
        cin>>val;
    vector<int>c(3,0);
    for(int i=0;i<3;i++) // storing the number of remainder
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]%3==i)
                c[i]++;
        }
    }    
    int cnt=0;
    while(*min_element(c.begin(),c.end())!=n/3)
    {
        for(int i=0;i<3;i++)
        {
            if(c[i]>n/3)
            {
                cnt++;
                c[i]--;
                c[(i+1)%3]++; // this one is for cyclic transfer 
            }
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}