/* DP based approach to find the nth catalan number */
#include<iostream>
using namespace std;
unsigned long Cat(unsigned int n)
{
    unsigned long cats[n+1];
    cats[0]=cats[1]=1;
    for(int i=2;i<=n;i++)
    {
        cats[i]=0;
        for(int j=0;j<i;j++){
            cats[i]+=cats[j]*cats[i-j-1];
        }
    }
    return cats[n];
}
int main()
{
    unsigned int n;
    cin>>n;
    cout<<Cat(n)<<endl;

    return 0;
}
