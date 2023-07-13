#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> dist;
    int c,r;
    for(int i= 0;i<n;i++){
        cin>>c>>r;
        dist.push_back({c-r,c+r});
    }

    sort(dist.begin(),dist.end(),comp);

    int cnt = 1; // the no of circles we consider 
    // 1 cause the first circle is always considered
    int prev = dist[0].second;
    for(int i=1;i<n;i++){
        if(dist[i].first >= prev){
            cnt++;
            prev = dist[i].second;
        }
    }
    cout<<n-cnt<<endl; // no of circles excluded

    return 0;
}

/*
 * There are n circles arranged on x-y plane. All of them have their centers on x-axis.
 * You have to remove some of them, such that no two circles are overlapping after that.
 * Find the minimum number of circles that need to be removed.
 *
 * Input Format
 * First line contains a single integer, n, denoting the number of circles.
 * Next line contains two integers, c and r each, denoting the circle with radius r and center, (c,0).
 */
