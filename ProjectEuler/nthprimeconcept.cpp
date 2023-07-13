#include<iostream>
#include<vector>
bool prime(long n)//checking if n is prime
{
    if(n<=1)
        return false;
    else if(n==2)
        return true;
    else if(n%2==0)
        return false;
    else if(n<9)//for 5,7
        return true;
    else if(n%3==0)
        return false;
    else{
        long i=5;
        while(i*i<=n)
        {
            if(n%i==0)
                return false;
            if(n%(i+2)==0)
                return false;
            i+=6;
        }    
    }
    return true;
}
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<long>a{2,3};
    long n=10001,j=3;
    int c=2;
    while(c<n) //firstly storing all prime numbers within the bounds
    {
        j+=2;
        if(prime(j)){
            c++;
            a.push_back(j);
           // cout<<c<<" "<<j<<endl;
        }
    }
    int ind;
    cin>>ind;
    cout<<a[ind-1]<<endl;
    return 0;
}

