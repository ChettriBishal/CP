#include <iostream>
#include <cstring>
using namespace std;

int cs(int arr[], int n){
    int dp[23] = {0};
    
    dp[n] = 1; // one way to stay at n (base case) assuming it has reached
    
    for(int i = n-1; i >=0;i--){
        for(int j=1;j <= arr[i] && j + i <= n;j++){
            dp[i] += dp[i+j];
        }
    }
    
    return dp[0]; // no of ways to reach from 0th to nth step 

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}
