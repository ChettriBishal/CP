#include<bits/stdc++.h>
using namespace std;
bool check(int n) // to check if a number is prime
{
    if(n==1 or n==0)
        return false;
    for(int i=2;i*i<=n;i++)
        if(n%2==0)
            return false;
    return true;
}
void solve()
{
    string s;
    cin>>s;
    int num=0; // to store the name value
    for(int i=0;i<s.length();i++)
    {
        num+=(tolower(s[i])-'a')+1;
    }
    int cnt=1;
    for(int i=2;i<=num;i++)
    {
        if(check(i)) // if i is prime
        {
            int temp=0;
            if(num% i ==0){
                while(num%i==0){
                    num=num/i;
                    temp++;
                }
                cnt=cnt*(temp+1);
            }
        }
    }
    if(s.length()<=cnt)
        cout<<"IN\n";
    else
        cout<<"OUT\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
    

}

