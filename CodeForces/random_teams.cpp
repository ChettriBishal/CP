#include<iostream>
using namespace std;
typedef long long ll;
ll nC2(ll n) // returns the number of pairs
{
    return (n*(n-1)/2);
}
int main()
{   
    ll n,m; // n= no of players..m=no of teams
    cin>>n>>m;
    ll a=n/m; // no of players per team
    ll b=n%m; // extra no of players who were not assigned teams 
    ll min=nC2(a) * (m-b) + nC2(a+1)*b; // min evenly dividing and taking care of remaining students as well 
    ll max=nC2(n-m+1); // putting max in one group only // other groups will contain only one student 
    cout<<min<<" "<<max<<"\n";
    return 0;
    
}
/* 
 * nC2(a+1) is finding the sum of count of no of players from 1 till a
 * player 1 ...player 2... player 3... player a
 */
