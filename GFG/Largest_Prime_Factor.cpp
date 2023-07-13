#include<bits/stdc++.h>
using namespace std;

int largest_prime_factor(int n)
{
    long long res = -1;

    while(n%2 == 0){
        res = 2;
        n>>=1;
    }
    
    while(n% 3 == 0){
        res = 3;
        n /= 3;
    }

    /*
     * Then check for every prime number like this
     * 5 and 7 (ie 5+2)
     * 11 (ie 5+6) and 13 (ie 11+2)
     */
    for(int i =5;i*i<=n;i+=6)
    {
        while(n % i == 0){
            //cout<<n<<endl;
            res = i;
            n /= i;
        }
        while(n %(i+2)==0){
            //cout<<n<<endl;
            res = (i+2);
            n /= (i+2);
        }
    }

    if(n > res){
        res = n;
    }

    return res;

}


int main()
{
    int n;
    cin>>n;
    cout<<largest_prime_factor(n)<<endl; // no of factors

    return 0;
}
