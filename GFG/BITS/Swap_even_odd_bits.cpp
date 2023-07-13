#include<iostream>
using namespace std;

int swap_bits(int n)
{
    int even_bits = (n & 0xAAAAAAAA); // to obtain the even bits of the number
    even_bits = even_bits >> 1;  // shifting even bits to right --> odd positions

    int odd_bits = (n & 0x55555555); // to obtain all the odd bits of the number
    odd_bits = odd_bits << 1; // shifting odd bits to left -> even positions 

    return even_bits | odd_bits ;
}

int main()
{
    int num;
    cout<<"Enter a number to swap it's even and odd bits\n";
    cin>>num; // 23 
    cout<<swap_bits(num)<<endl; / 43

    return 0;
}
