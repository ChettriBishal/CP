/* To find the i_th bit from the right */
#include<bits/stdc++.h>
using namespace std;
int find_bit(int n,int i)
{
    if(n&(1<<i)) return 1;
    else return 0;
}
int main()
{
    cout<<"Enter a number ";
    int n,i;
    cin>>n;
    string s= bitset<16>(n).to_string();
    cout<<"Binary representation of n: "<<s<<endl;
    cout<<"Enter the value of i to check the bit: ";
    cin>>i;
    cout<<"The i th bit of "<<n<<" is "<<find_bit(n,i)<<endl;
    return 0;

}
