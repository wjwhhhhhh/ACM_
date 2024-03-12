#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
vector<int> f(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    fir(i, 0, a.size())
    {
        ans.push_back(a[b[i]]);
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> m >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tem;
            cin >> tem;
            tem--;
            a[i].push_back(tem);
        }
    }
    set<vector<int>> ans;
    if (n <= 20)
    {
        for (int i = 1; i < 1 << n; i++)
        {
            vector<int> aa(m);
            iota(aa.begin(), aa.end(), 0);
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    aa = f(aa, a[j]);
                    for (auto c : aa)
                    {
                        cout << c << ' ';
                    }
                    cout << endl;
                }
            }
            ans.insert(aa);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> has;
            for (vector<int> c : ans)
            {
                has.push_back((c, a[i]));
            }
            ans.insert(a[i]);
            for (auto c : has)
            {
                ans.insert(c);
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}