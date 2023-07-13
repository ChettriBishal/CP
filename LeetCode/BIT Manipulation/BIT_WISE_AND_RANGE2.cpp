class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0; // cnt upto which the bits ---> from left are same ie starting from MSB
        while(left != right){
            left >>= 1; // ---->
            right >>=1;
            cnt++;
        }
        return (left <<cnt); // <---
    }
};
