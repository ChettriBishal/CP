#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
	int t,y,x;    // y is the time for which candle burns
	cin>>t>>y>>x;
	if(t>=y) // t is the time when the gf arrives
		cout<<x*y<<endl;
	else
		cout<<x*t+1<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
/*
Consider the cases:
1. t>=y 
then the time when the candles will be burning is:
Time:                 t   t-1    t-2  .....   t-y+1    ------> y seconds
No of candles lit:    x    x      x   .....     x      ------> x*y candles 
                                                              1 is NOT added here cause the candle we started out with at time 0 will also be extinguished by time 't'

2. t<y
Then we just need to count the number of candles till time t as they will be burning till that time (as t<y):
Time:                 1    2     3   ......   t      ------> t seconds
No of candles lit:    x    x     x   ......   x      ------> x*t + 1 candles
                                                            1 is added cause the candle which was there initially (at time 0) will also be burning
*/
