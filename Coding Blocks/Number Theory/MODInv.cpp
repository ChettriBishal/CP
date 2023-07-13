#include<iostream>
using namespace std;
int extgcd(int ,int,int &,int &); // extended gcd
void modinv(int a,int m)
{
    int x,y;
    int hcf=extgcd(a,m,x,y);
    // inverse exists only if the gcd(a,m)=1
    if(hcf!=1){
        cout<<"Inverse does not exist\n";
    }
    else{
        int b=(x%m+m)%m;
        cout<<"Modular muliplicative inverse: "<<b<<endl;
    }
}
int extgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int hcf = extgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;

    return hcf;
}
int main()
{
    int a=3,m=11;
    // modulo multiplicative inverse of 3 wrt 11 
    // 3*4 %11 =1
    // thus will be 4
    modinv(a,m);

    return 0;

}
