#include<iostream>
using namespace std;
int x,y,gcd;
void ExtendedEuclid(int a,int b)
{
    // base case
    if(b==0){
        x=1;
        y=0;
        gcd=a;
        return;
    }
    // Recursive Case
    ExtendedEuclid(b,a%b);
    int cx=y; // current x
    int cy= x-(a/b)*y; // current y
    
    cout<<cx<<" "<<cy<<endl;

    x= cx;
    y= cy;
}
int main()
{   
    cout<<"18 x + 30 y = gcd(18,30)"<<endl;
    ExtendedEuclid(18,30);
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    
    return 0;
}
