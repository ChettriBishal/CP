class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> bis;
        int k =0;
        for(int i=0;i<students.size();i++){
            if(students[i] == sandwiches[k]){
                k++;
            }
            else{
                bis.push(students[i]);
            }
        }
        
        int cnt  = 0; // to count the number of rotations 
        while(!bis.empty() && cnt < bis.size()){ // rotations should be less than size cause after bis.size() rotations you'd get the original queue back
            if(bis.front() == sandwiches[k]){
                k++;
                bis.pop();
                cnt = 0;
            }
            else{
                int val = bis.front();
                bis.pop();
                bis.push(val);
                cnt++;
            }
        }
       return bis.size(); 
    }
};
