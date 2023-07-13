#include<bits/stdc++.h>
using namespace std;


// Recursive Top Down approach
int lcs(string s1,string s2,int i,int j,vector<vector<int>>& dp)
{
    if(i == s1.length() || j == s2.length()){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i] == s2[j]){
        return dp[i][j] =  1+ lcs(s1,s2,i+1,j+1,dp);
    }
    
    int opt1 = lcs(s1,s2,i,j+1,dp);
    int opt2 = lcs(s1,s2,i+1,j,dp);

    return dp[i][j] = max(opt1,opt2);

}


int main()
{
    string a,b;
    cin>>a>>b;
    int n1 = a.length();
    int n2 = b.length();
    vector<vector<int>> dp(n1, vector<int>(n2,-1)); // n1 X n2

    cout<<lcs(a,b,0,0,dp)<<endl;
    
}

