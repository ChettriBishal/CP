#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(m+1);
    for(int &x:a)
        cin>>x;
    int friends=0;
    for(int i=0;i<m;i++)
    {
        int bis,cnt=0;
        bis=a[m]^a[i]; // bits which were different will be set
        cnt=__builtin_popcount(bis);
        if(cnt<=k) friends++;        
    }
    cout<<friends<<endl;
    return 0;
}
/*
 * Or you can even use bitset to count the number of 1's after xor 
    bitset<16>b1(bis);
    cnt=b1.count();
 */
