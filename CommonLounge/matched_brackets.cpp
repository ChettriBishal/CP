#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int>a(n);
	for(int &x:a)
		cin>>x;
	int depth=0,len=0,maxdepth=0,maxlen=0,depth_pos=0,len_pos=0;
	for(int i=0;i<n;i++)
	{
		len++; 
		if(a[i]==1) // opening brackets
		{
			depth++;
			if(depth>maxdepth){
				maxdepth=depth;
				depth_pos=i+1;
			}
		}
		else{               //closing brackets
			depth--;
			if(depth==0) // balanced now
			{
				if(len>maxlen){
					maxlen=len;
					len_pos=i-len+1;
				}
				len=0; // clean slate
			}
		}
	}
	cout<<maxdepth<<" "<<depth_pos<<" "<<maxlen<<" "<<len_pos+1<<endl;
	return 0;
}
