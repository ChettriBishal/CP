/*
Given a number N, complete the following tasks,
Task 1. Generate a new number from N by changing the zeroes in the binary representation of N to 1.
Task  2. Find the difference between N and the newly generated number.
*/
#include<bits/stdc++.h>
using namespace std;

int changebits(int n)
{
    int noofbits = log2(n) +1;
    int mask = (1 << noofbits) -1; // all 1111 type of
    mask ^= n;
    
    int res = mask | n;
    return res;
}

int main()
{
    cout<<"Enter a number to invert all the zeroes \n";
    int n;
    cin>>n;
    string nbin = bitset<16>(n).to_string();
    cout<<n<<" = "<<nbin<<endl;
    int inverted = changebits(n);

    cout<<inverted;
    nbin = bitset<16>(inverted).to_string();
    cout<<" = "<<nbin<<endl;

    return 0;
}
/*
Pseudocode:
1. Count the number of bits required to represent the number.

2. Set all the bits to 1.

3. XOR the new number formed (after setting the bit ) with the given number 
and you get a difference of two number.

4. Add this number to given number.

*/
