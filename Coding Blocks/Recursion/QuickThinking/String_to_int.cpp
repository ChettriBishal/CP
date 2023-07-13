#include<iostream>
#include<cstring>
using namespace std;

int strtoint(char * a, int n)
{
    // base case
    if(n==0){
        return 0;
    }

    int dig= a[n-1]-'0';
    int subprob= strtoint(a,n-1);
    
    return subprob * 10 + dig; // like 143 = 14 * 10 + 3
}

int main()
{
    cout<<"Enter a string to convert into integer\n";
    char a[30];
    cin>>a;
    
    cout<<"Integer\n";
    int res = strtoint(a,strlen(a));
    
    // adding to prove it's integer
    cout<<"res+303 = "<<res+303<<endl; 

    return 0;
}
