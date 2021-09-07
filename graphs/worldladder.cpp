#include<bits/stdc++.h>
using namespace std;
string beg,target;
int cnt=0;
int bfs(string arr[6], string start)
{
    int i,j;
    queue<string> Q;
    Q.push(start);
    while(!Q.empty())
    {

        string a=Q.front();

        for(j=0;j<a.size();j++)
        {
            a=Q.front();
            for(char c='a';c<='z';c++)
            {
                a[j]=c;
                if(a==target)
                    return cnt+1;
                string *it;
                it=find(arr, arr+6, a);
                if(it!=arr+6)
                {
                    cout<<*it<<"\t";
                    Q.pop();
                    Q.push(*it);
                    cnt++;
                    *it="";
                }
            }
        }
    }
}
int main()
{
    int i;
    string arr[6];
    cin>>beg>>target;
    for(i=0;i<6;i++)
    {
        cin>>arr[i];
    }
    cout<<bfs(arr,beg);
    return 0;
}
/*
hit cog
hot dot dog lot log cog
*/
