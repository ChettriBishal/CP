class Solution {
public:
    int binaryGap(int n) {
        int last = -1; // last index where 1 was found
        int res = 0;
        for(int i=31;i>=0;i--){
            if(n & (1 << i)){
                if(last >= 0){
                    res = max(res, last - i);
                }
                last = i;
            }
        }
        return res;
    }
};
/*
We can even use it in this way 
for (int i = 0; i < 32; ++i)
            if (((n >> i) & 1) > 0) {
                if (last >= 0)
                    ans = Math.max(ans, i - last);
                last = i;
            }
*/
