class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int pop[2052] = {0};
        for(auto &vec: logs){
            pop[vec[0]]++; // birth --> inclusion
            pop[vec[1]]--; // death --> exclusion
        }
        int res =0;
        for(int i= 1950;i<=2050;i++){
            pop[i] += pop[i-1];
            if(pop[i] > pop[res])
                res = i;
        }
        return res;
    }
};
// We can mark the start and end of each life as +1 and -1 on the timeline.
// Then, we go through timeline from 1950 to 2050 and accumulate the current population for each year.
