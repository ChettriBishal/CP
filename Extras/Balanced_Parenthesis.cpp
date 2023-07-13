#include<bits/stdc++.h>
using namespace std;

bool check_parenthesis(string st)
{
    int n= (int) st.length();
    stack<char> br;
    
    for(int i=0;i<n;i++){
        if(st[i] == '(' || st[i] == '{' || st[i] == '[')
            br.push(st[i]);
        else{
            if(br.empty())
                return false;
            else{
                char temp = br.top();
                br.pop();
                if(st[i] == ')' && temp != '(')
                    return false;
                if(st[i] == ']' && temp != '[')
                    return false;
                if(st[i] == '}' && temp != '{')
                    return false;
            }
        }
    }

    return br.empty(); // a balanced parenthesis would be empty by now
}

int main()
{
    string s;
    cin>>s;
    
    if(check_parenthesis(s)){
        cout<<"Balanced\n";
    }
    else{
        cout<<"Not Balanced\n";
    }

    return 0;
}

/*
 * The logic is we push the opening brackets into the stack 
 * When we encounter a closing bracket we will check if the last character in the stack acts as a complementary opening
 * one or not like '(' and ')' 
 * If this doesn't satisfy we return false
 * Finally the stack would be empty after the traversal
*/
