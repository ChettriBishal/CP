/* To set ith bit */
#include<bits/stdc++.h>
using namespace std;
void set_b(int& n,int i)
{
    n=n|(1<<i);
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
    cout<<"Enter the value of i to set the bit: ";
    int i; cin>>i;
    set_b(n,i);
    cout<<"After: "<<n<<" --> ";
    binaryrep(n);

    return 0;
}
