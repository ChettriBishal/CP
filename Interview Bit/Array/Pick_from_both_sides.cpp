int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    vector<int> pre(n,0), suff(n,0);
    pre[0] = A[0];

    for(int i=1;i < n;i++)
        pre[i] = pre[i-1] + A[i];

    suff[n-1] = A[n-1];

    for(int i=n-2; i>= 0;i --)
        suff[i] = suff[i+1] + A[i];

    int res = max(pre[B-1], suff[n-B]);

    int j = n-1;

    for(int i=B-2;i >=0;i--,j--){
        res = max(res , pre[i] + suff[j]);
    }
    return res;
}
