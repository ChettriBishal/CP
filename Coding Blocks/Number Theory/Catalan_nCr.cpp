#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll nCr(int n,int r)
{
    ll num=1,den=1;
    if(r!=0){
        while(r){
            num*=n;
            den*=r;
            ll m= __gcd(num,den);
            num/=m;
            den/=m;
            n--;
            r--;
        }
    }
    else
        num=1;

    return num;

}
int main()
{
    int n;
    cin>>n;
    cout<<nCr(2*n,n)/(n+1)<<endl;
    return 0;


}
