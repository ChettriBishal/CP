Class Solution{
public:
    const long long MOD = 1000000007;
    map<int,long long> dp;
    long long count(long long );
    int countFriendsPairings(int n) 
    { 
        int res= count((long long) n);
        return res;
    }
};    

long long Solution:: count(long long  n)
{
    if( n <= 1){
        return 1;
    }
    if(dp[n]){
        return dp[n];
    }
    // first option --> go alone
    long long first_opt = count(n-1);
    
    // or take one person with you 
    // Choosing your partner = nC2 ways = (n-1)
    long second_opt = (n-1)* count(n-2);
    
    dp[n] = ((first_opt % MOD) + (second_opt % MOD)) % MOD;
    return dp[n];
}
