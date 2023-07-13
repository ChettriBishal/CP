#include<iostream>
using namespace std;
int main()
{
   const long long num = 600851475143;
   long long n=num;
   int i=2;
   long gfac=0;
   while(i*i<=n)
   {
       if(n%i==0)
       {
           n/=i;
           gfac=i;
       }
       else i++;  // this is important if i is not a factor then move on to the next
   }
   if(n>gfac) gfac=n;
   cout<<gfac<<endl;
   return 0;
}