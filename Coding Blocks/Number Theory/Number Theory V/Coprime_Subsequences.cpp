/* Using mobius function and inclusion-exclusion principle */
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
const ll mod=1e9+7;
int a[N],primecnt[N],mobius[N];

int freq[N], pw[N];
void Mobiusfunc()
{
    fill(a,a+N,1);
    for(int i=2;i*i<N;i++)
    {
        if(primecnt[i]) continue;
        for(int j=i;j<N;j+=i)
        {
            primecnt[j]++;
            a[j]*=i;
        }
    }   
    for(int i=1;i<N;i++){
        if(a[i]==i){
            if(primecnt[i]%2==1)
                mobius[i]= -1;
            else
                mobius[i]=1;
        }
        else
            mobius[i]=0;
    }
}


int main()
{
    Mobiusfunc();
    int n;
    cin>>n;
    ll res=0ll;
    int val[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
        freq[val[i]]++; 
    }
    pw[0]=1; // 2^0=1
    for(int i=1;i<N;i++) // to store values of 2^ i 
    {
        pw[i]=pw[i-1]*2;
        pw[i]%=mod;
    }
    for(int i=1;i<N;i++){
        int cnt=0;
        for(int j=i;j<N;j+=i) // going through all the multiples of i
        {
            cnt+=freq[j];
        }
        // no of numbers divisible by i
        // cnt(x)
        int tot_subsequences=pw[cnt]-1;
        res+=mobius[i]*tot_subsequences;
        res = (res % mod + mod) % mod;
    }
    cout<<res<<endl;
}
// https://codeforces.com/problemset/problem/803/F
