#include<bits/stdc++.h>
using namespace std;
int set_bits1(int n) // first method takes more time O(logN)
{
    int cnt=0;
    while(n){
        cnt+=(n&1);
        n>>=1; // right shift to traverse all bits
    }
    return cnt;
}
int set_bits2(int n) // second method more efficient  O(no of set bits)
{
    int cnt=0;
    while(n){
        n=n & (n-1);
        cnt++;
    }
    return cnt;
}
void binaryrep(int n)
{
    string s=bitset<16>(n).to_string();
    cout<<s<<"\n";
}
int main()
{
    cout<<"Enter a number to count set bits\n";
    int n;
    cin>>n;
    binaryrep(n);
    cout<<"No of set bits: \n"<<set_bits1(n)<<"\n"<<set_bits2(n)<<"\n";
    return 0;

}
