#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << 2 << endl;
        cout << "1" << endl;
        cout << "1 2" << endl;
        return 0;
    }
    k--;
    vector<int> fa;
    int root = 0;
    while (k)
    {
        if (k & 1)
        {
            fa.push_back(root);
            root = fa.size();
            k--;
        }
        if (k == 0)
            break;
        fa.push_back(root);
        fa.push_back(fa.size());
        k >>= 1;
    }
    int siz = fa.size() + 1;
    vector<int> w(fa.size() + 1);
    w.back() = 1;
    vector<vector<int>> edge(siz);
    for (int i = fa.size() - 1; i >= 0; i--)
    {
        edge[fa[i]].push_back(i + 1);
    }
    for (int i = fa.size() - 1; i >= 0; i--)
    {
        chmax(w[fa[i]], (int)edge[fa[i]].size() * w[i + 1]);
    }
    function<void(int)> dfs = [&](int u) {
        for (auto c : edge[u])
        {
            w[c] = w[u] / edge[u].size();
            dfs(c);
        }
    };
    dfs(0);
    cout << siz << endl;
    for (auto c : fa)
        cout << c + 1 << ' ';
    cout << endl;
    for (auto c : w)
        cout << c << " ";
    return 0;
}