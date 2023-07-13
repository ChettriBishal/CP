/* to update the ith bit with binary value specified by the user */
#include<bits/stdc++.h>
using namespace std;
void update_bit(int& n,int i,int v) // updating the ith bit with v [0,1]
{
    // firstly we unset the ith bit
    int mask=~(1<<i);
    n=n & mask;
    n=n|(v<<i); // then updation takes place 
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
    cout<<"Enter values for i and v\nTo update the bit at ith from right with v : ";
    int i,v; cin>>i>>v;
    update_bit(n,i,v);
    cout<<"After: "<<n<<" --> ";
    binaryrep(n);
    return 0;
}
