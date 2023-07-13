bool comp(vector<int>b1,vector<int>b2)
{
    return b1[1] > b2[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int res = 0;
        int noofboxes =0;
        for(int i=0;i<boxTypes.size();i++)
        {
            noofboxes += boxTypes[i][0];
            res += (boxTypes[i][0] * boxTypes[i][1]);
            if(noofboxes >= truckSize){
                while(noofboxes > truckSize){
                    noofboxes --;
                    res -= (boxTypes[i][1]);
                }
                return res;
            }
            
        }
        return res;
    }
};
