#include <bits/stdc++.h>
using namespace std;
struct twostring_hash
{
    using ui64 = unsigned long long;
    ui64 base1, base2;
    vector<ui64> p1, p2;
    vector<vector<ui64>> h;
    twostring_hash(vector<string> &a)
    {
        int n = a.size(), m = a[0].size();
        init(n, m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                h[i][j] = h[i][j - 1] * base1 + a[i - 1][j - 1];
        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++)
                h[i][j] += h[i - 1][j] * base2;
    }
    void init(int l, int r, ui64 b1 = 131, ui64 b2 = 1331)
    {
        base1 = b1, base2 = b2;
        p1.resize(l + 1);
        p2.resize(r + 1);
        p1[0] = p2[0] = 1;
        for (int i = 1; i <= l; i++)
            p1[i] = p1[i - 1] * b1;
        for (int i = 1; i <= r; i++)
            p2[i] = p2[i - 1] * b2;
        h.resize(l + 1, vector<ui64>(r + 1));
    }
    ui64 get(pair<int, int> a, pair<int, int> b)
    {
        b.first++, b.second++;
        return h[b.first][b.second] - h[a.first][b.second] * p2[b.first - a.first] -
               h[b.first][a.second] * p1[b.second - a.second] +
               h[a.first][a.second] * p1[b.first - a.first] * p2[b.second - a.second];
    }
};
void solve()
{
    int n1, m1;
    cin >> n1 >> m1;
    vector<string> a(n1);
    for (int i = 0; i < n1; i++)
        cin >> a[i];
    int n2, m2;
    cin >> n2 >> m2;
    vector<string> b(n2);
    for (int i = 0; i < n2; i++)
        cin >> b[i];
    twostring_hash ha(a), hb(b);
    int ans = 0;
    // cout << ha.get({0, 1}, {1, 2}) << endl;
    // cout << hb.get({0, 0}, {n2 - 1, m2 - 1});
    for (int i = n2 - 1; i < n1; i++)
    {
        for (int j = m2 - 1; j < m1; j++)
        {
            if (ha.get({i - n2 + 1, j - m2 + 1}, {i, j}) == hb.get({0, 0}, {n2 - 1, m2 - 1}))
                ans++;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}