#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin>>n;
    if(n%4==3) // 3
        cout<<0<<endl;
    else if(n%4==0) // 4
        cout<<1<<" "<<n<<endl;
    else if(n%4==1) // 5
        cout<<1<<" "<<1<<endl;
    else // 6
        cout<<2<<" "<<n<<" "<<1<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;

}

/*
 * 0  1  2  3  4  5  6  7  8  9  10 11 
 * ----------  ----------  -----------
 *     0           0            0 
 */
