#include<bits/stdc++.h>
using namespace std;
bool check(int n) // checks if the number has two consecutive bits set
{
    return (n&(n>>1));
}
int main()
{
    int k;
    cin>>k;
    int i=1,j=0;
    int val=0;
    while(true)
    {
        if(check(i)==0){ // the number does not have consecutive bits set
            j++;
            val=i;
        }
        if(j==k){
            cout<<val;
            break;
        }
        i++;
    }
    return 0;
}
