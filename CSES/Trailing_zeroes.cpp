#include<iostream>
using namespace std;
typedef long long ll;
int cnt(ll n)
{
    int c=0;
    for(ll i=5;n/i>=1;i*=5)
        c+=(n/i);
    return c;
}
int main()
{
    ll n;
    cin>>n;
    cout<<cnt(n)<<endl;
    return 0;
}
 
/* To count the no of trailing zeroes in n!
 * The approach is to count the number of 5 and 2 cause they contribute to zeroes
 * But the number of 2's in prime factors of n is always greater than or equal to the number of 5's 
 * Hence we only count the number of 5's
 *
 * We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s.
 So if we count 5s in prime factors, we are done.
 How to count the total number of 5s in prime factors of n!?
 A simple way is to calculate floor(n/5). 
 For example, 7! has one 5, 10! has two 5s. It is not done yet, there is one more thing to consider.
 Numbers like 25, 125, etc have more than one 5.
 For example, if we consider 28! we get one extra 5 and the number of 0s becomes 6.
 Handling this is simple, first, divide n by 5 and remove all single 5s, then divide by 25 to remove extra 5s, and so on.
 Following is the summarized formula for counting trailing 0s.
 Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
*/
 
