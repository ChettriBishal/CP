/* Bottom UP approach --> Iterative */
#include<iostream>
#include<climits>
#include<map>
using namespace std;

map<int,int> dp;

int minsteps(int n)
{
    dp[1] = 0;

    for(int  i=2;i<=n;i++){
        int a,b,c; 
        tie(a,b,c) = make_tuple(INT_MAX,INT_MAX,INT_MAX);
            
        if(i % 2 == 0){
            a = dp[i/2];
        }
        if(i % 3 == 0){
            b = dp[i/3];
        }
        c = dp[i-1];

        dp[i] = min(a,min(b,c)) + 1;
    }

    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int res = minsteps(n);
    printf("The minimum no of steps to reach from %d to 1 is: %d\n ",n,res);

    return 0;
}
