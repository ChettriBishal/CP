class Solution{
public:
    vector<int> findprimes(int n){
        vector<bool> primes(n+3,true);
        primes[0] = primes[1] = false;
        for(int i =4;i<=n;i+=2){
            primes[i] = false;
        }
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(long j =i*2;j<=n;j+=i){
                    primes[j] = false;
                }
            }
        }
        // now store the primes in vector
        vector<int>res ;
        res.push_back(2);
        for(int i=3;i<=n;i+=2){
            if(primes[i]){
                res.push_back(i);
            }
        }
        return res;
    }
    
    vector<int> orderedPrime(int n){
        vector<int> primes = findprimes(n);
        vector<int> res;
        int cnt =1;
        for(int i=0;i<primes.size();i++){
            if(n % primes[i]== 0){
                int p = 0;
                while(n % primes[i] == 0){
                    ++p;
                    n /= primes[i];
                }
                res.push_back(p);
                cnt  *= (p+1);
            }
        }
        if(n != 1){
            res.push_back(1);
            cnt *= 2;
        }
        sort(res.begin(),res.end());
        res.push_back(cnt);
        return res;
    }
};
