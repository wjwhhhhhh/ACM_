#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int M=998244353;
int fac[1001000];
int find(int n,int m)
{
    if(n==m)return 1;
    else if(m==1)return fac[n];
    else return (find(n-1,m)+find(n-1,m-1)*(n-m+1)%M)%M;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fac[i]=(fac[i-1]+i)%M;
    if(n==m)
    {
        cout<<"1"<<endl;
    }
    else if(m==1)
    {
        cout<<fac[n]<<endl;
    }
    else
    {
        cout<<find(n,m)<<endl;
    }
    return 0;
}