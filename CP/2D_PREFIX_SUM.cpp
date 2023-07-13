#include<iostream>
#include<vector>
using namespace std;
int n ,m;
bool isvalid(int i,int j){ // to check if the given coordinates are valid 
    return i<n && j<m && i>=0 && j >=0;
}
void build(vector<vector<int>>& mat,vector<vector<int>>& pre) // to build the prefix sum matrix
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int curr = mat[i][j];
            if(isvalid(i-1,j))
                curr += pre[i-1][j];
            if(isvalid(i,j-1))
                curr += pre[i][j-1];
            if(isvalid(i-1,j-1))
                curr -= pre[i-1][j-1];
            pre[i][j] = curr;
        }
    }
}

int query(vector<vector<int>>& pre,int x1,int y1,int x2,int y2) // to take queries
{
    int sum = pre[x2][y2];
    if(isvalid(x2,y1-1))
        sum -= pre[x2][y1-1];
    if(isvalid(x1-1,y2))
        sum -= pre[x1-1][y2];
    if(isvalid(x1-1,y1-1))
        sum += pre[x1-1][y1-1];

    return sum;

}

int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    vector<vector<int>> pre(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    // initialise the prefix array
    build(mat,pre);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<< " ";
        }cout<<endl;
    }

    /*
     *cout<<endl<<"Prefix Sum \n";
     *for(int i=0;i<n;i++){
     *    for(int j=0;j<m;j++){
     *        cout<<pre[i][j]<< " ";
     *    }cout<<endl;
     *}
     */

    int q;
    cin>>q;
    cout<<"queries -- > "<<q<<endl;
    int x1,y1,x2,y2;
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        printf("%d %d %d %d -----> ",x1,y1,x2,y2);
        cout<<query(pre,x1,y1,x2,y2)<<endl;
    }

    return 0;
}
