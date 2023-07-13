#include<iostream>
#include<iomanip>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    double prob=0.0f;
    for(int i=1;i<=n;i++)
    {
        prob+=(double)1/i;
    }
    prob*=n;
    cout<<fixed<<setprecision(2);
    cout<<prob<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
    

}
