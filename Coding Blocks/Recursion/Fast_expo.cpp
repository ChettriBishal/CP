#include<iostream>
using namespace std;
int fexpo(int a, int b)
{
    if(b==0)
        return 1;
    int subprob=fexpo(a,b/2); // smaller sub-problem
    if(b&1) 
        return a* subprob*subprob;
    return subprob*subprob;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<fexpo(a,b)<<endl;
    
    return 0;
}
