#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
string str[2];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n,q;
    cin>>n>>q;
    cin>>str[0]>>str[1];
    str[0]=" "+str[0],str[1]=" "+str[1];
    vector<int> a(n+1);
    iota(a.begin(),a.end(),0);
    vector<int> o(2*n+1);
    for(int i=1;i<=n;i++)o[i]=i,o[i+n]=i;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(o[x]>o[y])swap(x,y);
        auto get=query([x],0[y]);
    }
    return 0;
}