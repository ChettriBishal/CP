// Given a number N. Find its unique prime factors in increasing order.

#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if( n==1) return false;
    for(int i=2;i*i<=n;i++){
        if( n% i== 0)
            return false;
    }
    return true;
}

vector<int>AllPrimeFactors(int n) {
    set<int> st;
    for(int i=2;i*i<=n;i++){
        if(isprime(i)){
            while( n% i == 0){
                st.insert(i);
                n /=i;
            }
        }
    }
    if(n != 1) st.insert(n);
    vector<int> res(st.begin(),st.end());
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> factors = AllPrimeFactors(n); // store the factors in sorted order in 'factors'
    for(auto k: factors){
        cout<<k<<" ";
    }

    cout<<endl;

    return 0;
}


