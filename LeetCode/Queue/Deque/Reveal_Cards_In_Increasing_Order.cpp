class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        vector<int> result(n);
        deque<int> dq;
        
        for(int i=0;i<n;i++)
            dq.push_back(i);
        
        sort(deck.begin(), deck.end());
        
        for(int i=0;i<n;i++){
            result[dq.front()] = deck[i];
            dq.pop_front();
            dq.push_back(dq.front()); // pushing the next element at the back 
            dq.pop_front();
        }
        
        return result;
    }
};
