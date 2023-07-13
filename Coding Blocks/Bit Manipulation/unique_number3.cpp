#include<iostream>
using namespace std;
int main()
{
    // largest integer has 64 bits
    int cnt[64]={};  // to store the positions of set bits
    int n,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        int j=0;
        while(d){
            cnt[j++]+= (d & 1); // updating that pos for cnt (will affect only when bit is set)
            d>>=1; // traversing all bits 
        }
    }
    int res=0,base=1;
    // now iterating through the count array
    for(int i=0;i<64;i++){ // creating the number out of binary representation 
        
        cnt[i]%=3; //if occuring thrice or once 
        res=cnt[i]*base+res; // converting to decimal 2^i * 1/0 
        base*=2;
    }
    cout<<res<<"\n";
    return 0;
}
/*
 * For the unique number sum of bits at every position is 3*N +1 
 * Or simply cnt[i]%3 = 1
 * However for numbers which occur thrice it will be of the form 3*N
 * Or simply cnt[i]%3 = 0
 * */
