#include<bits/stdc++.h>
using namespace std;
int ten(string s)
{
    int pos=s.find('.');
    int num=s.length()-1-pos;
    return num;
}
int w_dec(string s) // to convert string into integer without decimal like 7.89---->789
{
   int val=0,b=1;
   for(int i=(int)s.length()-1;i>=0;i--)
   {
      if(s[i]!='.'){
        val+=b*(s[i]-'0');
        b*=10;
      }  
   }
   return val;
}

int main()
{
    string s;
    cin>>s;
    int no=ten(s); // to find the denominator in terms of 
    int t=1;
    while(no--) 
        t*=10;
    int up=w_dec(s);
    int fac=gcd(up,t); // this the gcd b/w these two values
    up/=fac;
    t/=fac;
    cout<<"Fractional Form \n";
    cout<<"  "<<up<<endl;
    cout<<"  ---"<<endl;
    cout<<"   "<<t<<endl;
    cout<<"Improper Fraction\n";
    cout<<"  "<<up%t<<endl;
    cout<<up/t<<"---"<<endl;
    cout<<"  "<<t<<endl;

    return 0;
}
/*
say we have 7.89 then it can be written as 789/100 we first find the power of ten (like 2 in this case) then find the gcd between the numerator 
and denominator and write answers on the basis of that
*/
