#include<bits/stdc++.h> //bis
using namespace std;
string &changepm(string &s) //all pm cases except 12
{   //for pm cases add 12 to convert into 24 format
    int k=int(s[0]-'0')*10+int(s[1]-'0')+12;
    s[1]=char(k%10+'0');
    s[0]=char(k/10+'0');
    return s;
}
string &changeam(string &s) //only when we have 12 AM
{
    int k=int(s[0]-'0')*10+int(s[1]-'0')-12;
    s[1]=char(k%10+'0');
    s[0]=char(k/10+'0');
    return s;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string p,t1; 
        cin>>p>>t1;//p is the time 12:01 t1 =AM
        if(t1[0]=='P')
        {   
            if(p[0]=='1' && p[1]=='2'){}
            else
                p=changepm(p);
        }
        else if(p[0]=='1' && p[1]=='2' && t1[0]=='A')
            p=changeam(p);
        //cout<<p<<endl;
        int n;
        cin>>n;
        while(n--)
        {
            string a,b,t2,t3;
            cin>>a>>t2>>b>>t3;
            if(t2[0]=='P')
            {
                if(a[0]=='1' && a[1]=='2'){}
                else
                    a=changepm(a);
            }
            else if(a[0]=='1' && a[1]=='2' && t2[0]=='A')
                a=changeam(a);
            if(t3[0]=='P')
            {
                if(b[0]=='1' && b[1]=='2'){}
                else
                    b=changepm(b);
            }
            else if(b[0]=='1' && b[1]=='2' && t3[0]=='A')
                b=changeam(b);
            //cout<<a<<" "<<b<<endl;
            if(p>=a && p<=b)
                cout<<1;
            else
                cout<<0;
            // cout<<endl;
            
        }
        cout<<endl;
    }
    return 0;
}
