#include<iostream>
using namespace std;

int profit(int N, int Capc, int* wt, int* prices)
{
    // base case

    if(N==0 || Capc==0){
        return 0;
    }

    int res=0;
    int inc=0, exc=0;

    // on including the current item
    if(wt[N-1]<=Capc){
        inc = prices[N-1] + profit(N-1, Capc- wt[N-1],wt,prices); 
    }
    
    // on excluding the current item
    exc = 0 + profit(N-1,Capc,wt,prices);
    
    res=max(inc,exc);

    return res;
}

int main()
{
    int weights[]={1,2,3,5};
    int prices[]={40,20,30,100};

    int N=4;
    int Capc=7; // max-weight capacity the bag can withstand

    cout<<profit(N, Capc,weights,prices)<<endl;
    // 140
    return 0;
}
