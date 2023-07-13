#include <iostream>
#include <cstring>
using namespace std;
int dp[23];
int cs(int arr[], int n, int idx){
    if(idx == n){ // we reached the nth step
        return 1;
    }
    if(dp[idx] != -1)
        return dp[idx];
    
    int cnt = 0;
    
    for(int jump = 1;jump <= arr[idx]; jump++){
        if(jump + idx <= n){
            cnt += cs(arr,n,idx+jump);
        }
        else 
            break;
    }
    
    return dp[idx] = cnt;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n,0)<<endl;
}
