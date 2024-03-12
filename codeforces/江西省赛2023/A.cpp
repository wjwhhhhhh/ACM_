#include <bits/stdc++.h>
using namespace std;
void solves()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a<=b*c)cout<<"1"<<'\n';
    else cout<<"0"<<'\n';
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
