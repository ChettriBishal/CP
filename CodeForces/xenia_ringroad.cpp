/*
Bishal
11-Apr-21 1:27:39 AM
https://codeforces.com/problemset/problem/339/B
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int &x:a)
        cin>>x;
    long long time=a[0]-1;
    for(int i=1;i<m;i++){
        if(a[i]>=a[i-1]) time+=(a[i]-a[i-1]);
        else
            time+=(n-a[i-1]+a[i]);
    }
    cout<<time<<endl;
    return 0;
    
}
