#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt[123]={}; // to store the count of characters
    string s;
    cin>>s;
    for(int i=0;i<(int)s.length();i++)
        cnt[s[i]]++;
    int res=cnt['i'];
    res=min(res,cnt['t']);
    res=min(res,cnt['e']/3);
    res=min(res,(cnt['n']-1)/2);
    cout<<res<<"\n";
}
/*
 * required word = nineteen
 * 3 n's --> (3-1)/2 cause ending n can even be starting for required word
 * 1 t
 * 1 i
 * 3 e's 
 */
