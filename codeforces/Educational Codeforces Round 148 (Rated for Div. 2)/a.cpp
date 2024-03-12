#include <bits/stdc++.h>
using namespace std;
void solves()
{
    string tem;
    cin>>tem;
    bool fl=false;
    for(int i=0;i<tem.size()/2-1;i++)
    {
        if(tem[i]!=tem[i+1])fl=true;
    }
    if(fl)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solves();
    }
    return 0;
}