#include<bits/stdc++.h>
using namespace std;

set<string> ele;
void permute(char* a, int i,int len)
{
    if(i==len){
        a[i]='\0';
        ele.insert(a);
        return ;
    }
    
    for(int k=i;k<len;k++){
        swap(a[i],a[k]);
        permute(a,i+1,len);

        swap(a[i],a[k]);
    }

}

int main()
{
    char a[10];
    cin>>a;
    int len= (int)strlen(a); 
    permute(a,0,len);
    vector<string> res;
    for(auto k:ele){
        res.push_back(k);
    } 
    sort(res.begin(),res.end());

    for(auto k:res)
        cout<<k<<endl;

    return 0;
}
