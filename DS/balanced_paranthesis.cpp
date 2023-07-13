#include<iostream>
#include<map>
#include<stack>
using namespace std;
#ifdef bistimulus
#define focus(b) cerr<< (#b)<<" = ";cerr<<b;cerr<<endl;
#else
#define focus(b);
#endif
bool check_balanced(string s)
{
    stack<char>brackets;
    map<char,char>b; // to store the complementary closing brackets for the opening ones
    b['(']=')';
    b['{']='}';
    b['[']=']';
    for(int i=0;i<(int)s.length();i++)
    {
        if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            brackets.push(s[i]);
        else if(s[i]==')' or s[i]=='}' or s[i]==']')
        {
            if(brackets.empty() or s[i]!=b[brackets.top()]) 
                return false;
            else brackets.pop();
        }
    }
    return brackets.empty();
}
int main()
{
    cout<<"Enter a string to check if it's balanced\n";
    string s;
    getline(cin,s); // reads whitespaces too 
    if(check_balanced(s))
        cout<<"YES\n";
    else 
        cout<<"NO\n";
    return 0;
}
