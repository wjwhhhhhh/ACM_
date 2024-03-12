#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e9 + 7;
struct Tree_array
{
    vector<int> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    void init(int n)
    {
        maxx = n;
        tr.assign(n + 1, 0);
    }
    void insert(int x, int c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(i, c);
    }
    int ask(int x)
    {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            (res += tr[i]) %= M;
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(int x, int c)
    {
        (tr[x] += c) %= M;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return r[x] < r[y]; });
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[r[i]]++;
    map<int, int> li;
    int idx = 1;
    mp[0]++;
    vector<int> has;
    for (auto [x, y] : mp)
    {
        has.push_back(x);
        li[x] = idx++;
    }
    vector<int> dp(idx);
    if (li.find(n) == li.end())
    {
        cout << "0" << endl;
        return 0;
    }
    Tree_array tr(idx + 1);
    tr.insert(1, 1);
    for (int i = 0; i < n; i++)
    {
        int j = o[i];
        auto left = lower_bound(has.begin(), has.end(), l[j]) - has.begin() + 1;
        auto right = lower_bound(has.begin(), has.end(), r[j]) - has.begin();
        dp[li[r[i]]] = (tr.ask(right) - tr.ask(left - 1)) % M;
    }
    cout << (dp[li[n]] + M) % M;
    return 0;
}