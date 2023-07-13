#include <iostream>
#include <vector>
//#include "bistimulus.h"
using namespace std;

void unboundedKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

    vector<int> dp(cap+1,0);


    for(int c = 1; c <= cap;c++){
        for(int i=0;i < n;i++){
            if(weight[i] <= c){
                dp[c] = max(dp[c], dp[c - weight[i]] + val[i]);
            }
        }
    }

    //debug(dp);

    cout << dp[cap] << endl;
}


int main() {

#ifdef Bis
    freopen("input.txt","r",stdin);
#endif

    int n;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {

        cin >> val[i];
    }
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    int cap;
    cin >> cap;

    unboundedKnapsack(n, val, weight, cap);


}
