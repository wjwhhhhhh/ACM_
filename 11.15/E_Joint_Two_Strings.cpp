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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    string T;
    cin >> T;
    vector<string> all(n);
    fir(i, 0, n) cin >> all[i];
    vector<int> id;
    string lon;
    lon = T + '#';
    fir(i, 0, n)
    {
        lon += all[i];
        id.push_back(lon.size() - 1);
    }
    vector<int> cntq(T.size() + 1), cnth(T.size() + 1);
    vector<vector<int>> edq(T.size() + 1), edh(T.size() + 1);
    auto p = prefix_function(lon);
    for (auto c : id)
    {
        cntq[p[c]]++;
    }
    for (int i = 0; i < T.size(); i++)
    {
        edq[p[i]].push_back(i + 1);
    }
    reverse(T.begin(), T.end());
    fir(i, 0, n) reverse(all[i].begin(), all[i].end());
    lon = T + '#';
    fir(i, 0, n)
    {
        lon += all[i];
    }
    p = prefix_function(lon);
    for (int i = 0; i < T.size(); i++)
    {
        edh[p[i]].push_back(i + 1);
    }
    for (auto c : id)
    {
        cnth[p[c]]++;
    }
    i64 ans = 0;
    function<void(int)> dfs = [&](int u) {
        for (auto c : edh[u])
        {
            dfs(c);
            cnth[u] += cnth[c];
        }
    };
    dfs(0);
    cerr << "ok" << endl;
    function<void(int)> dfs1 = [&](int u) {
        ans += cntq[u] * cnth[T.size() - u];
        for (auto c : edq[u])
        {
            dfs1(c);
        }
    };
    dfs1(0);
    cout << ans << endl;
    return 0;
}