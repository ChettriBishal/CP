/*
 Given a string str and another string patt.
 Find the character in patt that is present at the minimum index in str.
 If no character of patt is present in str then print ‘No character present’.
*/

#include<bits/stdc++.h>
using namespace std;

void printMinIndexChar(string str,string patt)
{
   unordered_map<char,int> um;

   int ind = INT_MAX; // index of character having minimum index 

   int m = str.size();
   int n = patt.size(); 

   // Store the first index of each character of 'str'

   for(int i=0;i<m;i++){
       if(um.find(str[i]) == um.end())
            um[str[i]] = i;
   }

   // traverse the string 'patt'

   for(int i=0;i<n;i++){
       if(um.find(patt[i]) != um.end() && um[patt[i]] < ind){
           ind = um[patt[i]];
       }
   }

   if(ind != INT_MAX ){
       cout<<"Minimum Indexed Character: "<<str[ind]<<" at index "<<ind<<endl;
   }
   // no character of 'patt' is present in 'str'
   else{
        cout<<"No character present \n";
   }

}

int main()
{
    string str,patt;
    cin>>str>>patt;
    printMinIndexChar(str,patt);

    return 0;
}
// https://www.geeksforgeeks.org/find-character-first-string-present-minimum-index-second-string/
