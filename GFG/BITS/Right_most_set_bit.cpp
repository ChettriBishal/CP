#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int pos = log2(n & (~(n-1))) +1 ; // observe this
  
    string binaryn = bitset<16>(n).to_string();
    cout<<n<<"  =  "<<binaryn<<endl;
    cout<<"Position of right most set bit is at index "<<pos<<endl;

    return 0;
}



