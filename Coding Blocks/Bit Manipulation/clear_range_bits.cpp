/*
 * To clear bits in range specified */

#include<bits/stdc++.h>
using namespace std;
void binaryrep(int);
void clear_range(int& n,int i,int j) // clearing the last k bits
{
    int mask1=(~0<<(j+1)); // left shifting by j+1 bits (+1 for 1 based length)
    cout<<"mask 1: ";
    binaryrep(mask1);
    int mask2=(1<<i)-1; // 2^i -1
    cout<<"mask 2: ";
    binaryrep(mask2);
    int mask=mask1 | mask2; // final mask is result of these
    cout<<"mask  : ";
    binaryrep(mask);
    cout<<"n     : ";
    binaryrep(n);
    n=n & mask; // finally clearing the range
}
void binaryrep(int n) // print the binary representation of n
{
    string s=bitset<16>(n).to_string();
    cout<<s<<endl;
}
int main()
{ 
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<"Before: "<<n<<" --> ";
    binaryrep(n);
    cout<<"Enter values for i and j\nTo clear bits from i (left) to j (right): ";
    int i,j; cin>>i>>j;
    clear_range(n,i,j);
    cout<<"After: "<<n<<" --> ";
    binaryrep(n);
    cout<<"\n\n";
    cout<<"Binary representation of -1 or ~0\n";
    binaryrep(~0);
    return 0;
}
