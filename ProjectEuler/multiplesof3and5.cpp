#include<iostream>
using namespace std;
#define t 999
int sumn(int n)
{
    long int f=t/n;
    long int u=n*(f*(f+1)/2);
    return u;
}
int main()
{
    long int s=sumn(5)+sumn(3)-sumn(15);
    cout<<s<<endl;
    return 0;
}


/*

    int i;
    long int sum=0;
    for(i=3;i<1000;i++){
        if(i%3==0 || i%5==0)
            sum+=i;
    }
    cout<<sum<<endl;
    return 0;
*/
