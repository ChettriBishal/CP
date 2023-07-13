class Solution {
public:
     unordered_map<int,int> al, bob;
     long asum, bsum;
     Solution(){
         asum = 0;
         bsum = 0;
     }
    vector<int> iterate(vector<int> & first, vector<int> & second){
        for(int i=0;i<first.size();i++){
            int temp = bsum - asum + 2 * first[i];
            temp /= 2;
            if(bob.find(temp) != bob.end()){
                return {first[i],temp};
            }
        }
        // now trying the second vector
        for(int i=0;i<second.size();i++){
            int temp = asum - bsum + 2 * second[i];
            temp /= 2;
            if(al.find(temp) != al.end()){
                return {temp, second[i]};
            }
        }
        return {};
    }
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
       
        for(int &x: aliceSizes){
            al[x] ++;
            asum += x;
        }
        for(int &x: bobSizes){
            bob[x] ++;
            bsum += x;
        }
        return iterate(aliceSizes,bobSizes);
    }
};
