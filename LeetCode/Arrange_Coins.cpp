#include<iostream>
using namespace std;

long long arrangeCoins(int n) {
    long long start = 0;
    long long end = n;
    while(start <= end)
    {
        cout<<start<<" "<<end<<" ";
        long long mid = ( start + end) /2;
        cout<<mid<<endl;
        long long curr = (mid* (mid+1))/2;

        if( curr == n){
            return mid;
        }
        else if(curr < n){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<start<<" "<<end<<endl;
    return end; // when exiting the loop ( end < start )
}

int main()
{
    int n;
    cin>>n;
    cout<<arrangeCoins(n)<<endl;
    return 0;
}
