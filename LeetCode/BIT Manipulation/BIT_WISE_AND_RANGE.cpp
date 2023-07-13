class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res= 0;
        for(int bit = 31;bit >= 0 ; bit--){
            if((left & (1 <<bit)) != (right & (1 <<bit))){
                break;
            } 
            else{ // will continue as long as the ith bits are same in both
                res |= (left & (1<<bit));   // considering the ith bit in the result
            }
        }
        return res;
    }
};
