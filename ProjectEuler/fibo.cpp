/* to calculate the sum of first 4 million even fibonacci numbers*/
#include<iostream>
using namespace std;
int main()
{
    long a=0,b=2,c=2,sum=0; // c is initialised to 2 in this case as it needs to be added 
    while(c<4000'000)
    {
        sum+=c; //c is always gonna be even
        c=4*b+a;
        a=b;
        b=c;
    }
    cout<<sum<<endl;
    return 0;
}
/*
#include<iostream>  // this one's direct but takes more time
using namespace std;
int main()
{
    long int a=1,b=1,c=0,sum=0;
    while(c<4000'000){
        if(c%2==0)
            sum+=c;
        c=a+b;
        a=b;
        b=c;
    }
    cout<<sum<<endl;
    return 0;
    
}
*/
