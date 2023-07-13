#include<iostream>
using namespace std;

int longest_consecutive_ones(int n)
{
    int cnt =0;
    while(n){
        n = (n & (n<<1));
        cnt++;
    }

    return cnt;

}

int main()
{
    cout<<"Enter a number to find the longest_consecutive_ones in it's binary representation:\n";
    int n;
    cin>>n;
    cout<<longest_consecutive_ones(n)<<endl;
    return 0;
}

/*
Using Bit Magic:
The idea is based on the concept that if we AND a bit sequence with a shifted version of itself,
we’re effectively removing the trailing 1 from every sequence of consecutive 1s.  

      11101111   (x)
    & 11011110   (x << 1)
    ----------
      11001110   (x & (x << 1)) 
        ^    ^
        |    |
   trailing 1 removed
So the operation x = (x & (x << 1)) reduces length of every sequence of 1s by one in binary representation of x.
If we keep doing this operation in a loop, we end up with x = 0.
The number of iterations required to reach 0 is actually length of the longest consecutive sequence of 1s.
*/
