#include<bits/stdc++.h>
using namespace std;
void clear_bit(int& n,int i)
{
    int mask=~(1<<i);
    n=n & mask;
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
    cout<<"Enter the value of i to clear the bit: ";
    int i; cin>>i;
    clear_bit(n,i);
    cout<<"After: "<<n<<" --> ";
    binaryrep(n);
    return 0;
}
