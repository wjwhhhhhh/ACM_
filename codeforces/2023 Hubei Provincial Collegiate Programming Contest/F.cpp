#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[2*N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> ans(n+5);
    ans[1]=1;
    for(int i=1;i<=2*n+2;i++)
    {
        cin>>a[i];
    }
    for(int i=4;i<2*n+2;i+=2)
    {
        if(a[i]==1)ans[i/2]=!ans[i/2-1];
        else ans[i/2]=ans[i/2-1];
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i])cout<<'a';
        else cout<<'b';
    }
    return 0;
}