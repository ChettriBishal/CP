class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto it = stable_partition(logs.begin(),logs.end(),[](const string & str){
            return isalpha(str[str.find(' ') + 1]);
        });
        sort(logs.begin(), it, [](const string & a, const string & b){
            auto sub1 = string(a.begin() + a.find(' '), a.end()); // substring after the identifier
            auto sub2 = string(b.begin() + b.find(' '), b.end());
            if(sub1 == sub2) // if the contents are the same then sort them on the basis of identifiers
            {
                return a < b;
                
            }
            else
                return sub1 < sub2;
        });
        // string a = logs[0];
        // string sub1(a.begin() +  a.find(' '), a.end());
        // cout<<"Here "<<sub1<<endl;
        
        return logs;
                                
    }
};
