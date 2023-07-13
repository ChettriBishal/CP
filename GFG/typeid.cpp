#include <bits/stdc++.h>
using namespace std;

#define print(x) cout<< (#x) <<" : " << x << "\n"

int main() {
	
    print(typeid(int).name());
    print(typeid(float).name());
    print(typeid(char).name());
    print(typeid(string).name());
    print(typeid(int*).name());
    print(typeid(double).name());
    print(typeid(char*).name());
    print(typeid(float*).name());
    print(typeid(double*).name());
    print(typeid(set<int>()).name());
    print(typeid(map<int,int>()).name());
    print(typeid(set<int>::iterator).name());
    print(typeid(vector<int>()).name());
    print(typeid(size_t).name());
    print(typeid(unsigned int).name());
    print(typeid(long long).name());
    print(typeid(int []).name());
    print(typeid(pair<int,int>).name());
    print(typeid(tuple<int,int, float>).name());
    print(typeid(int&).name());
    print(typeid(int**).name());
	
    return 0;
}
/*
Output
typeid(int).name() : i
typeid(float).name() : f
typeid(char).name() : c
typeid(string).name() : NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
typeid(int*).name() : Pi
typeid(double).name() : d
typeid(char*).name() : Pc
typeid(float*).name() : Pf
typeid(double*).name() : Pd
typeid(set&lt;int&gt;()).name() : FSt3setIiSt4lessIiESaIiEEvE
typeid(map&lt;int,int&gt;()).name() : FSt3mapIiiSt4lessIiESaISt4pairIKiiEEEvE
typeid(set&lt;int&gt;::iterator).name() : St23_Rb_tree_const_iteratorIiE
typeid(vector&lt;int&gt;()).name() : FSt6vectorIiSaIiEEvE
typeid(size_t).name() : m
typeid(unsigned int).name() : j
typeid(long long).name() : x
typeid(int []).name() : A_i
typeid(pair&lt;int,int&gt;).name() : St4pairIiiE
typeid(tuple&lt;int,int, float&gt;).name() : St5tupleIJiifEE
typeid(int&amp;).name() : i
typeid(int**).name() : PPi
*/
