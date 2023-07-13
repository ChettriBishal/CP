/*Code N Code  Binomial Coefficient using modulo inverse */
#include<bits/stdc++.h>
using namespace std;

int F[1000001]; // to store the factorial of numbers 
#define P 1000000007

int power(int a, int b) // a^b 
{
    int res = 1;
    while(b){
        if(b&1){
            res = (res *1LL*  a) % P;
        }
        a = ( a* 1LL*a ) % P;
        b >>=1;
    }

    return res;
}

// nCk = n! % P/ (k! % P *(n-k)%P)
int C(int n,int k)
{
    if(k> n) // we can't choose a number more than what we have 
        return 0;
    int res = F[n]; // n ! 
    
    // since we're working under modulo P we can't divide directly
    // thus res / F[k] (under mod P ) --> res * modinverse(F[k])
    res = ( res *1LL* power(F[k],P-2)) % P;

    res  = (res *1LL* power(F[n-k],P-2)) % P;
    
    return res;

}

int main()
{
    F[0] = F[1] = 1; // base conditions 
    
    for(int i=2;i<=1000000;i++)
        F[i] = (F[i-1]* 1LL* i) % P; // n!= (n-1)! *n;

    int q;
    int n,k;

    cin>>q;
    while(q--){
        cin>>n>>k;

        cout<<C(n, k)<<endl;
    }
   
    return 0;
}

