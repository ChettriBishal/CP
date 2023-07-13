long long getSum(int A[],int n)
{
    const long long MOD = 1000000007;
    long long sum = 0;
    sort(A,A+n);
    do{
        std:: stringstream ss;
        for(int i=0;i<n;i++){
            ss << A[i];
        }
        int val;
        ss>>val;
        sum = ((sum + val)% MOD)%MOD;
    }while(next_permutation(A,A+n));
  
    return sum;
}
