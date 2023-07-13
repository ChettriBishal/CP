class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size())
            return false;
        vector<int> ok(1003,0);
        for(int i=0;i<arr.size();i++)
            ok[arr[i]]++;
        for(int i=0;i<target.size();i++)
            ok[target[i]]--;
        for(int i=1;i<=1000;i++){
            if(ok[i]!= 0)
                return false;
        }
        return true;
    }
};
