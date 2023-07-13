bool isprime(int n)
{
    if(n == 1) return false;
    for(int i=2;i*i<=n;i++){
        if(n %i ==0)
            return false;
    }
    return true;
}
int common_divisor(int a, int b) // method similar to finding the number of divisors
{
    int g = __gcd(a,b); // gcd of a and b
    // find the no of divisors of gcd(a,b)
    int cnt =1; // cnt of divisors
    for(int i=2;i<=g;i++)
    {
        if(i>2 && i% 2== 0) continue;
        if(g % i == 0 && isprime(i)){
            int p =0; // count of i ...to get the powers
            while(g % i == 0){
                g/=i;
                p++;
            }
            cnt *= (p+1);
        }
    }
    if(g != 1){ // if the number remaining is prime after all with count 1 ie powers possible = 0,1 = 2 powers
        cnt *=2;
    }
    return cnt;
    
}
