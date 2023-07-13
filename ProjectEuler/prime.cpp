/*Largest prime divisor*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long int fac[2],b=0;
    const long long n=600851475143L;
    //cin>>n;
    for(long int i=2;i*i<=n;i++)
    {
        if(n%i==0){
            fac[0]=i;
            fac[1]=n/i;
            for(long int t=0;t<2;t++)
            {
                bool check=true;
                for(long int j=2;j*j<=fac[t];j++) // checking if factor is prime or not
                {
                    if(fac[t]%j==0){
                        check=false;
                        break;
                    }
                }
                if(check && fac[t]>b) b=fac[t];
            }
        }
    }
    cout<<b<<endl;
}