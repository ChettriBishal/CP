/* To toggle the i_th bit of a number */
#include<bits/stdc++.h>
using namespace std;
void binaryrep(int n)
{
    string s=bitset<16>(n).to_string();
    cout<<s<<"\n";
}
void toggle(int& n,int i) // toggle the i_th bit of number n
{
    n=n^(1<<i);
}
int main()
{
    cout<<"Enter a number\n";
    int n;
    cin>>n;
    binaryrep(n);
    cout<<"Enter the value of i to toggle\n";
    int i;
    cin>>i;
    toggle(n,i);
    cout<<n<<"\n";
    binaryrep(n);
    return 0;



}
