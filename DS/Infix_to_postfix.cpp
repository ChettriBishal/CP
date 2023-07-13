#include<bits/stdc++.h>
using namespace std;
bool higherprec(char a,char b) // checks if a has higher or equal precedence compared to b
{
    map<char,int>v; // to store the value pair for comparison 
    v['^']=6;
    v['*']=5,v['/']=5;
    v['-']=4,v['+']=4;
    if(v[a]==v[b]) // if they are equal then also left one is favoured like + and -
        return true;
    return v[a]>v[b];
}
string topostfix(string s)
{
    stack<char>a; // stack to store the operators and opening brackets
    set<char>operators{'*','+','-','^','/'}; // operators
    set<char>obrackets{'(','{','['};  // opening brackets
    set<char>cbrackets{')','}',']'}; // closing brackets
    string res="";
    for(int i=0;i<(int)s.length();i++)
    {
        if(isdigit(s[i]) or isalpha(s[i]))
            res+=s[i];
        else if(operators.count(s[i])>0) // if it's an operator
        {
        // while stack is not empty and a.top() is not an opening bracket and a.top() has higher or equal precedence than s[i]
            while(!a.empty() && obrackets.count(a.top())==0 && higherprec(a.top(),s[i])) 
            {
                res+=a.top(); // a.top() will be appended to the result
                a.pop();
            }
            a.push(s[i]); // pushing the current operator into the stack
        }
        else if(obrackets.count(s[i])) // if it's an opening bracket
            a.push(s[i]);
        else if(cbrackets.count(s[i])) // if it's a closing bracket
        {
            while(!a.empty() && obrackets.count(a.top())==0) // not opening paranthesis
            {
                res+=a.top();
                a.pop();
            }
            a.pop(); // will pop the opening paranthesis
        }
    }
    while(!a.empty()){ // remaining operators with less precedence placed at the end
        res+=a.top();
        a.pop();
    }
    return res;
}
int main()
{
    string s; //A+B*C-D*E
    cout<<"Enter string to convert to postfix\n";
    getline(cin,s);
    string res=topostfix(s);
    cout<<res<<endl; //ABC*+DE*-
    return 0;

}
