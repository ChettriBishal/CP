class Solution {
	// This function returns the number of 1's in the binary representation of n
    int numBits(int n){
        int count = 0;
        while(n!= 0){
            count += n%2;
            n = n/2;
        }
        return count;
    }
    
	//custom comparator for the priority queue, which follows ascending pair.first, if pair.first equal, follows ascending pair.second
    struct comparator{
      bool operator() (pair<int,int> a, pair<int,int> b){
          if(a.first == b.first){
              return a.second > b.second;
          }
          return a.first > b.first;
      }  
    };
public:
    vector<int> sortByBits(vector<int>& arr) {
		//pair -> {numBits(i), i}
        priority_queue<pair<int,int>, vector<pair<int,int>> , comparator> pq;
        
        for(auto i: arr)
            pq.push({numBits(i), i});
        
        int idx = 0;
        
        while(!pq.empty()){
            arr[idx] = pq.top().second;
            idx++;
            pq.pop();
        }
        return arr;       
    }
};
