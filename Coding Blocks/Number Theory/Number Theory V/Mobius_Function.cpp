/*
 * To get mu(n) for values
 * mu(n)=0 if it has squared prime factors
 * mu(n)=1 if n is a square free positive number with even number of prime factors
 * mu(n)= -1 if n is a square free positive number with odd number of prime factors
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int a[N],primecount[N],mobius[N];
void Call_Mobius()
{
    fill(a,a+N,1); 
    
    for(int i=2;i*i<=N;i++){
        if(primecount[i]) continue;
        for(int j=i;j<=N;j+=i){
            primecount[j]++;
            a[j]*=i;
        }
    }
    for(int i=1;i<N;i++){
        if(a[i]==i){
            // square free number
            if(primecount[i]%2==1) // odd number of prime factors 
                mobius[i]=-1; 
            else
                mobius[i]=1;
        }
        else{
            mobius[i]=0;
        }
    }
}
int main()
{
    Call_Mobius();
    for(int i=1;i<51;i++){
        cout<<i<<" "<<mobius[i]<<endl;
    }
    return 0;
}
