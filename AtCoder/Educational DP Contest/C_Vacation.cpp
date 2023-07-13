#include<iostream>
#include<vector>
using namespace std;

struct activity{ // to store the activity the Taro does on a given day
    int A, B, C; 
};

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif

    int n;
    cin>>n;
    vector<activity> vec(n);
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        vec[i].A = a; // 0
        vec[i].B = b; // 1
        vec[i].C = c; // 2
    }

    vector<vector<int>> dp(n, vector<int> (3));
    // base cases
    dp[0][0] = vec[0].A;
    dp[0][1] = vec[0].B;
    dp[0][2] = vec[0].C; 

    for(int i=1;i<n;i++){
        // boy does activity A on day i 
        dp[i][0] = vec[i].A + max(dp[i-1][1],dp[i-1][2]);

        // boy does activity B on day i
        dp[i][1] = vec[i].B + max(dp[i-1][0],dp[i-1][2]);

        // boy does activity C on day i
        dp[i][2] = vec[i].C + max(dp[i-1][0],dp[i-1][1]);

    }


    int res= max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]));

    cout<<res<<endl;

    return 0;

}

// dp[n] ---> maximum possible happiness that the boy can achieve in first n days
// dp[n][0] --> maximum possible happiness in first n days : given he does activity 1 on day n 
// dp[n][1] --> maximum possible happiness in first n days : given he does activity 2 on day n 
// dp[n][2] --> maximum possible happiness in first n days : given he does activity 3 on day n 
