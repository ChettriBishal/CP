#include<iostream>
#include<set>
using namespace std;
typedef multiset<int>:: iterator It;
int main()
{
    int a[]={10,20,30,50,10,10,10,80};
    
    int n=sizeof(a)/sizeof(int);

    multiset<int> m(a,a+n); // putting elements into the multiset from the array
    
    m.insert(70); // to insert
    
    cout<<"Multiset\n";
    for(auto k: m)
        cout<<k<<" ";
    cout<<endl;
    
    cout<<"Range of 10\n";

    // Using equal_range() function 

    pair<It,It> range= m.equal_range(10); // returns iterator to the first pos of 10 and last position of 10
    

    for(auto it=range.first;it!=range.second;it++)
        cout<<(*it)<<" ";
    cout<<"\n";
    // to print all elements which are in range [20,80)
    

    cout<<"In range [20,80)... 80 isn't included\n";
    for(auto it=m.lower_bound(20);it!=m.upper_bound(77);it++)
        cout<<(*it)<<" ";
    return 0;



}
