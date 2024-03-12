#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    map<string,int> mp;
    mp["shitou"]=0,mp["bu"]=1,mp["jiandao"]=2;
    string a;
    cin>>a;
    int ans=(mp[a]+2)%3;
    for(auto [x,y]:mp)
    {
        if(y==ans)cout<<x<<endl;
    }
    return 0;
}