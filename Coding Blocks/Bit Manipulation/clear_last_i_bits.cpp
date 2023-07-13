/* to clear the last k bits from the right 
 * Binary representation of -1 is 111111111111111....
 * */
#include<bits/stdc++.h>
using namespace std;
void binaryrep(int);
void clear_last(int& n,int k) // clearing the last k bits
{
    int mask=(-1<<k); // left shifting by k bits
    cout<<"n   : ";
    binaryrep(n);
    cout<<"mask: ";
    binaryrep(mask);
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
    cout<<"Enter values for i \nTo clear all k bits from right: ";
    int k; cin>>k;
    clear_last(n,k);
    cout<<"After: "<<n<<" --> ";
    binaryrep(n);
    cout<<"\n\n";
    cout<<"Binary representation of -1 or ~0\n";
    binaryrep(-1);
    return 0;
}
