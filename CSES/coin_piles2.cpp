#include<iostream>
#include<algorithm>
using namespace std;
void solve()
{   
    long long a,b;
    cin>>a>>b;
    if(2*a-b>=0 and (2*a-b)%3==0 and 2*b-a>=0 and (2*b-a)%3==0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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
 * a,b
 * x= take 2 from a and 1 from b ...(no of times)
 * y= take 2 from b and 1 from a ...(no of times)
 * a=2x + 1y
 * b=2y + 1x
 * solving these two equations 
 * 2a-b=3x....ie 2a-b must be divisible by 3
 * 2b-a=3x....ie 2b-a must be divisible by 3
 */
