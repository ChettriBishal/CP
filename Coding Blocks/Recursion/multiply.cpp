/* to multiply two numbers using recursion without using * operator */
#include<iostream>
using namespace std;
typedef long long ll;
ll multiply(ll a,ll b)
{
    // base case
    if(b==1)
        return a;
    
    return a + multiply(a,b-1);
}
int main()
{   
    cout<<"Enter two numbers to multiply\n";
    int a,b;
    cin>>a>>b;
    cout<<multiply(a,b)<<endl;

    return 0;
}

/*
 * Say we multiply a*3 
 * a*3 = a+a+a
 * So we're repeatedly adding the numbers using recursion 
*/
