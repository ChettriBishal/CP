// time-limit: 1000
// problem-url: https://codeforces.com/group/yg7WhsFsAp/contest/355493/problem/P22
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#ifdef Bis 
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
using namespace std;
typedef long long ll;
#define setbits  __builtin_popcountll
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


signed main()
{
    io;
    int n;
    cin >> n;
    ll div[n+1];
    memset(div,0,sizeof(div));

    for(int i=1;i <=n;i++){
        for(int j=1;j *i<=n;j++)
            div[i*j]++; // increment the divisor count for i*j
    }

    ll res = 0;
    for(int i=1;i <= n;i++)
        res += div[i];

    cout << res <<endl;

    return 0;
}
