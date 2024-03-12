#include<bits/stdc++.h>
using namespace std;
const int N=1100;
char a[N][N];
using two=array<int,2>;
two fr[N][N];
int st[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        cin>>a[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='#')
            {
                dfs(i,j);
            }
        }
    }
}