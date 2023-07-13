#include<iostream>
#include<vector>
#include<string>
using namespace std;


int lcs(string& s1, string & s2, int i,int j, vector<vector<int>>& dp)  // to calculate the length of lcs
{
    if(i == s1.length() || j == s2.length())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(s1, s2, i+1,j+1, dp);

    int opt1 = lcs(s1,s2, i+1, j, dp);
    int opt2 = lcs(s1,s2, i, j+1, dp);

    return dp[i][j] = max(opt1, opt2);
}

string Getlcs(string & s1, string & s2)
{
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    int len = lcs(s1,s2,0,0,dp);
    
    int i,j;
    i = j= 0;
    string ans = ""; // resultant longest common subsequence
    while(len){
        if(s1[i] == s2[j]){
            ans += s1[i];
            i++;
            j++;
            len--;
        }
        else{
            if(dp[i+1][j] > dp[i][j+1]) // check if moving forward for which string yields a better result
                i++;
            else
                j++;
        }
    }
    return ans;
}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    string s, t;
    cin>>s>>t;

    cout<<Getlcs(s,t)<<endl;

    return 0;
}

