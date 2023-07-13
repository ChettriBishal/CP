#include<vector>
#include<iostream>
using namespace std;

int sumofdiv(int n) // to find for every factor
{
    int res = 0;
    for(int i= 1;i*i<=n;i++){
        if(n%i == 0){
            if(n/i == i){
                res += i;
            } 
            else
                res += ((n/i)+i);

        }
    }
    return res;
}

int sumofdivisors(int n)
{
    vector<int> bis;
    for(int i =1;i*i<=n;i++){
        if( n%i ==0){
            if( n/i == i ){
                bis.push_back(i);
            }
            else
            {
                bis.push_back(i); bis.push_back(n/i);
            }
        }
    }
    int sum = 0;
    for(auto k: bis){
        sum += sumofdiv(k);
    }

    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<sumofdivisors(n)<<endl;

    return 0;
}
