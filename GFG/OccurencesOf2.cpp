long long int numberOf2sinRange(long long int n)
{
    string res = "";
    for(int i= 0;i<=n;i++){
        res += to_string(i);
    }
    long long cnt = 0;
    for(int i=0;i<res.length();i++){
        if(res[i] == '2')
            cnt++;
    }
    return cnt;
}
