#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int res=0;
    for(int &x: a){ 
        cin>>x;
        res^=x;
    }
    // now find the first position of set bit in res
    int b=res,pos=0;
    while(b){
        if(b&1) break;
        pos++;
        b=b>>1;
    }
    int x=0,y=0;
    for(auto k:a){
        if(k&(1<<pos)) // if number's bit is set at position pos
            x^=k;          // x will give the first unique number
    }
    y=res^x; // other number 
    if(x>y) swap(x,y);
    cout<<x<<" "<<y<<"\n";
    return 0;
    
}
/*
 * At position pos only 1 unique number has set bit 
 * We obtain that useful information from "res" which is "pos"
 * Then we xor only those items which have set bit at pos.. 
 * x will in that manner give the first unique number
 * y will be xor of x and "res"
 * */
