class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
       vector<int> s0(n,0), s1(n,0), s2(n,0);
        
        s0[0] = 0; // no stock initially
        s1[0] = -prices[0]; // profit for buying the stock at 0th day
        s2[0] = -1; // any -ve value for comparison
        
        
        for(int i=1;i < n;i++){
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s0[i-1] - prices[i], s1[i-1]);
            s2[i] = s1[i-1] + prices[i];
        }
        
        return max(s0[n-1], s2[n-1]);
        
    }
};

/*
s0 --> s1 --> s2 --> s0

s0 -> Can buy after rest
s1 -> Can sell after buying
s2 -> Just sold, can only rest

There are three states, according to the action that you can take.

Hence, from there, you can now get the profit at a state at time i as:

s0[i] = max(s0[i - 1], s2[i - 1]); // Stay at s0, or rest from s2
s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]); // Stay at s1, or buy from s0
s2[i] = s1[i - 1] + prices[i]; // Only one way from s1
*/
