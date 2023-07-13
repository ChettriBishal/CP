#include<iostream>
using namespace std;
void solve()
{
    long long n;
    cin>>n;
    while(n%11)
    {
        n=n-111;
        if(n<0)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main()
{
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin>>t;
    while(t--)
        solve();


    return 0;

}
// https://codeforces.com/blog/entry/91195
