class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cntE = count_if(position.begin(),position.end(),[](int a){return !(a&1);});
        int cntO = count_if(position.begin(),position.end(),[](int a){return a&1;});
        if(cntE == position.size() or cntO == position.size())
            return 0;
        return min(cntE,cntO);
    }
};
