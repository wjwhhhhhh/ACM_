#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    char m;
    cin >> n >> m;
    string ans="";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        ans+=to_string(i)+"*"+to_string(j)+"="+to_string(i*j)+",";
    int cnt=0;
    for(auto i:ans)
    {
        if(i==m)cnt++;
    }
    cout << cnt << endl;
    return 0;
}