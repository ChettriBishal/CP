/*
 *Rearrange characters in a string such that no two adjacent are same
Input : 
str = "geeksforgeeks"
Output: 1
Explanation:
All the repeated characters of the 
given string can be rearranged so 
that no adjacent characters in the 
string is equal. Any correct 
rearrangement will show a output of 1.
Input : 
str = "bbbbb"
Output: 0
Explanation : 
Repeated characters in the string cannot 
be rearranged such that there should not 
be any adjacent repeated character.
 */

#include<bits/stdc++.h>
using namespace std;

const int max_char = 26;

class Key{
    public:
        int freq; // store the frequency of the character
        char ch;
        Key(int freq,char ch){
            this->freq = freq;
            this->ch = ch;
        }
};

class orderbyfreq{
    public:
        bool operator () (Key const& a,Key const& b) const{
            return a.freq < b.freq;
        }
};

void rearrange(string str)
{
    int n = str.size();

    // store the frequency of all characters in a string
    int count[max_char] = {0};

    for(int i=0;i<n;i++){
        count[str[i]-'a']++;
    }

    // insert all characters with their frequencies into a priority queue
    priority_queue<Key,vector<Key>,orderbyfreq> pq; 

    for(char c = 'a';c <= 'z'; c++){
        if(count[c-'a']){
            pq.push(Key{count[c-'a'],c});
        }
    }

    str = "";

    Key prev{-1,'#'}; // previous visited element

    // traverse the queue
    while(!pq.empty()){
        Key k = pq.top(); 
        pq.pop();
        str += k.ch;

        if( prev.freq > 0){
            pq.push(prev);
        }
        (k.freq)--;
        prev = k;
    }
    
    if( n != (int)str.length() ){
        cout<<"Not a valid string \n";
    }
    else{
        cout<<str<<endl;
    }

}

int main()
{
    cout<<"Enter a string to check if it can be rearranged\n";
    string s;
    cin>>s;
    rearrange(s);
    return 0;
}
