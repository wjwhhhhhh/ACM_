#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
map<pair<int, i64>, string > mp;
vector<i64> a(19), b(19);
char tr[]={'w','d','m'};
int trr[]={1,0,-1};
string ch(string a)
{
    string c = a;
    for (auto &i : c)
    {
        if (i == 'w')i = 'm';
        else if (i == 'm')i = 'w';
    }
    return c;
}
string find(int d, i64 res)
{
    bool fl = false;
    if (res < 0)
    {
        fl = true;
        res *= -1;
    }
    if (res > b[d])return "0";
    if (d < 0)
    {
        if (res == 0)
        {
            return "";
        }
        else return "0";
    }

    if (mp.find({d, res}) != mp.end())
    {
        if (fl)return ch(mp[ {d, res}]);
        else return mp[ {d, res}];
    }
    string ans="";
    for(int i=0;i<3;i++)
    {
        string tem=find(d+1,res-=trr[i]*a[d]);
        if(tem=="0")continue;
        ans=tr[i]+tem;
    }
    mp[{d,res}]=ans;
    return (fl?ch(ans):ans);
}
void solve()
{
    int n;
    cin >> n;

    int len = lower_bound(b.begin(), b.end(), abs(n)) - b.begin();
    cout << find(len, n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    a[0] = 1, b[0] = 1;
    for (int i = 1; i < 19; i++)a[i] = a[i - 1] * 3, b[i] = b[i - 1] + a[i];
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}