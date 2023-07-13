/* Sun Aug  8 19:06:34 2021
 *You are given an array of numbers and a target number(T) , print all unique combinations in the array whose sum equals the target number T. Note that each number in the array may only be used once in the combination.
 *Note:
 *
 *All numbers (including target) will be positive integers
 *Elements in the combination must be in non-descending order
 *There should be no duplicate combinations
 
 *Using Bits to get 2^n-1 subsets 
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
using namespace std;

vector<vector<int>> res;
void all_seqs(int* a,int n,int T)
{
    for(int i=1;i<(1<<n);i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            if( i & (1<<j)) {
                temp.push_back(a[j]);
            }
        }
        if(accumulate(temp.begin(),temp.end(),0) == T){
            sort(temp.begin(),temp.end());
            res.push_back(temp);
        }
        temp.clear();
    }
    sort(res.begin(),res.end());
}

// to remove duplicate vectors 
void removeduplicates(vector<vector<int>>& res)
{
    auto it = res.begin();
    bool ok = false;
    while(it != res.end()){
        if((it+1)==res.end()) break;
        if(*it == *(it+1)){
            res.erase(it);
            ok = true;
            break;
            it++;
        }
        if((it+1)!=res.end())
            it++;
    }
    if(ok) removeduplicates(res);
}
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int &x: a) cin>>x;

    int T;
    cin>>T;

    all_seqs(a,n,T);

    removeduplicates(res);
    sort(res.begin(),res.end());
    for(auto k: res){
        for(auto j: k)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
