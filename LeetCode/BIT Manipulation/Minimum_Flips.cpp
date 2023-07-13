class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i=0 ;i < 32;i++){
            if(c & (1<<i)){ // if the ith bit is set in c
               if((a & (1<<i)) || (b & (1<<i))) {}
                else flips++;
            }
            else{
                if(a& (1<<i)) flips++;
                if(b & (1<<i)) flips++;
            }
        }
        return flips;
    }
};
