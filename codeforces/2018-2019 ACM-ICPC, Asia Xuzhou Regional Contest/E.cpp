#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==m)
    {
        cout<<1.0/m<<endl;
    }
    else cout<<1.0/(m+1)<<endl;
    return 0;
}