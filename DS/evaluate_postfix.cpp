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
int postfix(string s) // assuming we only have binary operators
{
    stack<int>operands;
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
int main()
{
    cout<<"Enter a valid postfix expression to evaluate\n";
    string s;
    getline(cin,s);
    ll ans=postfix(s);
    cout<<s<<" = "<<ans<<endl;
    return 0;
}
