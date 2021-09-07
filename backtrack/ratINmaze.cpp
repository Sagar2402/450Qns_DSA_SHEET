#include<bits/stdc++.h>
using namespace std;

int xm[4]={1,0,0,-1};
int ym[4]={0,-1,1,0};
bool isSafe(int x, int y,vector<vector<int>> &m, int n)
    {
        if(x>=0 && x<n && y<n && y>=0 && m[x][y]==1)
            return true;
        return false;
    }
void find1(vector<vector<int>> m, int n, vector<string> &result, int x, int y, string s)
    {
        int x1,y1;
        for(int i=0;i<4;i++)
        {
            x1=x+xm[i];
            y1=y+ym[i];
            if(isSafe(x1,y1,m,n))
            {
                //cout<<x1<<"\t"<<y1<<endl;
                if(x1==n-1 && y1==n-1)
                {
                    if(i==0)
                        s+='D';
                    if(i==1)
                        s+='L';
                    if(i==2)
                        s+='R';
                    if(i==3)
                        s+='U';
                    result.push_back(s);
                    return;
                }
                else
                {
                    if(i==0)
                    {
                        m[x][y]=0;
                        find1(m,n,result,x1,y1,s+'D');
                    }

                    if(i==1)
                    {
                        m[x][y]=0;
                        find1(m,n,result,x1,y1,s+'L');
                    }

                    if(i==2)
                    {
                        m[x][y]=0;
                        find1(m,n,result,x1,y1,s+'R');
                    }

                    if(i==3)
                    {
                        m[x][y]=0;
                        find1(m,n,result,x1,y1,s+'U');
                    }

                }


            }
        }

    }
vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> result;
        find1(m,n,result,0,0,"");
        return result;
    }
int main()
{
    int i,j;
    vector<vector<int>> mat( 4 , vector<int> (4, 0));
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<string> result;
    result=findPath(mat,4);
    for(i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
/*
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
*/
