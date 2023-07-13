#include <iostream>
#include <cstring>
using namespace std;
int dp[23];
int cs(int n){
    
    if(n == 0) return 1;
    if(n < 0) return 0;
    
    if(dp[n] != -1)
        return dp[n];
        
    int way1 = cs(n-1);
    int way2 = cs(n-2);
    int way3 = cs(n-3);
    
    return dp[n] = way1 + way2 + way3;

}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}
