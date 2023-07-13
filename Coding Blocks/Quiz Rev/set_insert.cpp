#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int>s;
    pair<set<int>::iterator, bool> ret;
    s.insert(1);
    s.insert(5);
    s.insert(10);
    s.insert(3);
    ret = s.insert(11);   // 11 doesn't exist in set
    cout<<ret.second<<endl;
   
    ret=s.insert(10);   //10 exists already
    cout<<ret.second<<endl;
    return 0;
}

/*
The single element versions (1) return a pair, with its member pair::first set to an iterator pointing 
to either the newly inserted element or to the equivalent element already in the set.
The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent element already existed.
*/
