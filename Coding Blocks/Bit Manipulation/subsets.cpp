#include<iostream>
#include<string>
using namespace std;
void filterchars(string s,int n)
{
    int j=0;
    while(n>0){
        if(n&1) // if the bit is set
            cout<<s[j];
        j++;
        n>>=1; // traversing all bits
    }
    cout<<"\n";
}
void subsets(string s)
{
    int n=s.length();
    for(int i=0;i<(1<<n);i++)
        filterchars(s,i);
}
int main()
{
    cout<<"Enter a string to generate subsets of it's characters\n";
    string s;
    cin>>s;
    subsets(s);
    return 0;
}
