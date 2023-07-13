#include<bits/stdc++.h>
using namespace std;
#ifdef bistimulus
#define focus(b) cerr<< (#b)<<" = ";cerr<<b;cerr<<endl;
#else
#define focus(b);
#endif
typedef long long ll;
ll epow(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
ll postfix(string s) // assuming we only have binary operators
{
    stack<ll>operands;
    for(int i=0;i<(int)s.length();i++)
    {
        if(isdigit(s[i]))
            operands.push(s[i]-'0');
        else if(s[i]=='*' or s[i]=='+' or s[i]=='-' or s[i]=='/' or s[i]=='^') // operators
        {
            ll res=0;
            ll b=operands.top(); // second operand comes first
            operands.pop();
            ll a=operands.top(); // first operand
            operands.pop();
            switch(s[i])
            {
                case '*': res=a*b; break;
                case '+': res=a+b; break;
                case '-': res=a-b; break;
                case '/': res=a/b; break;
                case '^': res=epow(a,b); break;
            }
            operands.push(res);
        }
    }
    return operands.top(); // finally only one value remains
}
int prefix(string s)
{
    stack<ll>operands;
    for(int i=(int)s.length()-1;i>=0;i--) // travel backwards here
    {
        if(isdigit(s[i]))
            operands.push(s[i]-'0');
        else if(s[i]=='*' or s[i]=='+' or s[i]=='-' or s[i]=='/' or s[i]=='^') // operators
        {
            ll res=0;            // order of evaluatiion is still from left to right
            ll a=operands.top(); // first operand
            operands.pop();
            ll b=operands.top(); // second operand
            operands.pop();
            switch(s[i])
            {
                case '*': res=a*b; break;
                case '+': res=a+b; break;
                case '-': res=a-b; break;
                case '/': res=a/b; break;
                case '^': res=epow(a,b); break;
            }
            operands.push(res);
        }
    }
    return operands.top();
}
int main()
{
    cout<<"Enter a valid postfix expression to evaluate\n";
    string s;
    getline(cin,s); // 2 3 * 5 4 * + 9 -
    ll ans=postfix(s); // 17
    cout<<s<<" = "<<ans<<endl;
    cout<<"Enter a valid prefix expression to evaluate\n";
    getline(cin,s); // - + * 2 3 * 5 4 9  
    ans=prefix(s);  // 17
    cout<<s<<" = "<<ans<<endl;
    return 0;
}
