#include<iostream>
using namespace std;

// p -->precision upto p decimal places
float square_root(int n,int p)
{
    int s = 0;
    int e = n;
    
    float res = -1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        
        if(mid*mid==n){
            return mid;
        }

        if(mid*mid<n){
            res = mid;
            s= mid+1;
        }
        else{
           e=mid-1; 
        }
    }    
    
    float inc=0.1;

    for(int times=1;times<=p;times++){
        while(res*res<=n){
            res+=inc;
        }
        // we have overshot the value inside the while loop
        res= res-inc;
        inc=inc/10;
    }
    return res; 
}


int main()
{
    int n;
    cin>>n;

    cout<<square_root(n,3)<<endl;

    return 0;

}
