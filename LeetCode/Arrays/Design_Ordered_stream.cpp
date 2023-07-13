class OrderedStream {
public:
    int n;
    vector<string> ok;
    int cur =0;
    OrderedStream(int n) {
        ok.resize(n+1," ");
        this->n = n;
    }
    
    vector<string> insert(int idKey, string value) {
        ok[idKey-1] = value;
        vector<string> res;
        if( ok[cur] != " "){
            while(cur!= n && ok[cur] != " "){
                res.push_back(ok[cur++]);
            } 
        }
       
        if(res.size() == 0)
            return {};
        return res;
    }
};
