#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
void multiply(vector<int>&dig,int &n,int no)
{
    int carry=0; // carry over
    for(int i=0;i<n;i++){
        int prod=dig[i]*no+ carry;
        dig[i]=prod%10;
        carry=prod/10;
    }
    while(carry){
        dig[n]=carry%10;
        carry=carry/10;
        n++; 
    }   
}

void big_factorial(ll num)
{
    vector<int>dig(1000,0); // to store the digits
    dig[0]=1;
    int n=1; // no of digits to perform muliplication
    for(int i=2;i<=num;i++){
        multiply(dig,n,i);
    }
    // print the result
    for(int i=n-1;i>=0;i--)
        cout<<dig[i];
    cout<<"\n";

}
int main()
{
    ll num;
    cin>>num;
    big_factorial(num);
    return 0;

    
}
