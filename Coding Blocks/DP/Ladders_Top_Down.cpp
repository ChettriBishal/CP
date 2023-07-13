/* No of ways to reach the top of the ladder with N steps, taking at max k steps at a time*/
#include<iostream>
#include<map>
using namespace std;

map<int,int> dp;
int ways(int n,int k)
{
    if(n == 0) // one way to stay in the ground
        return 1; 

    if(dp[n]){
        return dp[n];
    }
    int cnt = 0;
    for(int i=1;i<=k;i++){
        if( n-i >=0 ){
            cnt += ways(n-i,k);
        }
    }

    return dp[n] = cnt;
    
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<"Ways = "<<ways(n,k)<<endl;

    return 0;
}
