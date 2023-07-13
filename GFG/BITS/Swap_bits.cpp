/*
Given a number x and two positions (from the right side) in the binary representation of x, 
write a function that swaps n bits at given two positions and returns the result.
It is also given that the two sets of bits do not overlap.

Method 1 
Let p1 and p2 be the two given positions.

Example 1 

Input:
x = 47 (00101111)
p1 = 1 (Start from the second bit from the right side)
p2 = 5 (Start from the 6th bit from the right side)
n = 3 (No of bits to be swapped)
Output:
227 (11100011)
The 3 bits starting from the second bit (from the right side) are 
swapped with 3 bits starting from 6th position (from the right side)


V.IMP


1) Move all bits of the first set to the rightmost side
   set1 =  (x >> p1) & ((1U << n) - 1)
Here the expression (1U << n) - 1 gives a number that 
contains last n bits set and other bits as 0. We do & 
with this expression so that bits other than the last 
n bits become 0.

2) Move all bits of second set to rightmost side
   set2 =  (x >> p2) & ((1U << n) - 1)
   
3) XOR the two sets of bits
   xor = (set1 ^ set2) 
   
4) Put the xor bits back to their original positions. 
   xor = (xor << p1) | (xor << p2)
   
5) Finally, XOR the xor with original number so 
   that the two sets are swapped.
   result = x ^ xor

*/

#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/swap-bits-in-a-given-number/
class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n)
    {
        int set1 = (x>>p1) & ((1U<<n) -1);
        int set2 = (x>>p2) & ((1U<<n) -1);
        int xort = set1 ^ set2;
        xort = (xort<<p1) | (xort <<p2);
        xort ^=x;
        return xort;
    }
};
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}
