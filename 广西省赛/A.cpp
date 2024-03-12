#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,k;
    int ans=0;
    cin>>a>>b>>c>>k;
    while(a+b<=k)
    {
        ans++;
        int x=min(k,a),y=k-x;
        a-=x,b-=y;
        b+=x,c+=y;
    }
    cout<<ans+1<<endl;
    return 0;
}