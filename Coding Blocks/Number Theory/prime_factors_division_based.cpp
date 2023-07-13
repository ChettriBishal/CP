/* Prime factors of a number by optimised trial divisions */
#include<bits/stdc++.h>
using namespace std;

void Printfactors(int n)
{
    vector<pair<int,int>> fact; // factors and it's count
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            fact.push_back({i,cnt});
        }
    }
    // if there is still a prime number remaining
    if(n!=1)
    {
        fact.push_back({n,1});
    }
    cout<<"The prime factors \n";
    for(auto k:fact)
        cout<<k.first<<" ^ "<<k.second<<"\n";

}

int main()
{
    cout<<"Enter a number to find its prime factors\n";
   
    int n;
    cin>>n;
    
    Printfactors(n);
    return 0;

}
