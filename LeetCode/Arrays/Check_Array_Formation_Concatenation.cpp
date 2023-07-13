class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> ps(101,-1); 
        
        for(int i=0;i<pieces.size();i++)
            ps[pieces[i][0]] = i; 
        
        for(int i=0;i<arr.size();){
            int p = ps[arr[i]];
            int j= 0;
            if(p == -1)
                return false;
            while(j < pieces[p].size() ){
                if(arr[i++] != pieces[p][j++])
                    return false;
            }
        }
        return true;
    }
};
/*
Since all elements are unique, we can map the first element in pieces to the piece position. 
Then, we just check if we have the right piece, and if so - try to fit it.

As values are within [0..100], we can use an array instead of a hashmap.
*/
