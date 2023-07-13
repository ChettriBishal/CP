string solve(vector<int> a) {
    int n= a.size();
    for(int i=0;i<n;i++){
        int k = a[i];
        for(int j=0;j<n;j++){
            if( i != j)
                k = __gcd(a[j],k);
        }
        if( k == 1){
            return  "YES";
        }
    }
    return "NO";
}
