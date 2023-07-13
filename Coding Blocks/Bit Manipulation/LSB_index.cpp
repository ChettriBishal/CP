/* To get the index of the least significant bit */
#include<bits/stdc++.h>
using namespace std;
int LSB(int n)
{
    int comp=-n; // -n = ~n+1
    //int comp2=(~n)+1;
    //cout<<comp2<<"\n";
    return log2(n & comp) +1;

}
void binaryrep(int n)
{
    string s=bitset<16>(n).to_string();
    cout<<s<<"\n";
}
int main()
{
    cout<<"Enter a number find it's LSB index <--\n";
    int n;
    cin>>n;
    binaryrep(n);
    cout<<"LSB at  "<<LSB(n)<<" from right\n";
    return 0;
}
/*
 * hello @bishal_c
 * log2(N&(-N)) +1 will give u position of first set bit (counting from right and 1 based indexing .
 * if n is a positive number , so -n will be a negative number and negative number are represented in 2’s compliment
 * ,which is ~n+1 , ~n has all the bits of n inverted due to which we get 0 in place of 1 and vice versa so when we add
 * 1 to ~n then that 1 occupies the first rightmost 0 in (~n)(which is same as rightmost 1 value in n) and other bits
 * have inverted values or zero values . so when we perform & operation we get only rightmost bit set in the function
 * ,and then we perform logn (base2) to get corresponding index.
 *
 * eg :- n = 1110010100
 * ~n= 0001101011
 * ~n+1=-n= 0001101100
 * (n&(-n))= 0000000100 = 4
 * log(4) =2
 * 2+1=3 which is the answer
 *
 * */


