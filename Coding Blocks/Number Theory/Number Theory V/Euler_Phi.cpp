/* Using the euler's formula for calculating phi(n)   */
#include<bits/stdc++.h>
using namespace std;
int phi(int n) 
{
    int num=n;
    vector<int> fact(n+3,-1); // to store the smallest prime factor for every number
    
    fact[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(fact[i]==-1){
            for(int j=i;j<=n;j+=i)
            {
                if(fact[j]==-1)
                    fact[j]=i;
            }
        }
    }
    set<int> cnt; //  prime factors for n
    while(n!=1){
        cnt.insert(fact[n]);
        n/=fact[n];
    }
    float res=1.0;
    for(auto k:cnt)
    {
        res*=(1.0-(1.0/(float)k));
    }
    res*=(float)num;

    return (int) res;

}
int main()
{
    cout<<"Enter a number to calculate no of coprimes\n";
    int n;
    cin>>n;
    cout<<phi(n)<<endl;

    return 0;


}
