#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = pair<int, int>;
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
    int n, m;
    cin >> n >> m;
    vector<vector<two>> edg(n);
    vector<int> ans(n, 1e9);
    for (int i = 0; i < m; i++)
    {
        int ci;
        cin >> ci;
        while (ci--)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            edg[a].emplace_back(two{b, i});
            edg[b].emplace_back(two{a, i});
        }
    }
    vector<vector<int>> pos(m);
    int t;
    cin >> t;
    fir(i, 0, t)
    {
        int tem;
        cin >> tem;
        tem--;
        pos[tem].push_back(i);
    }
    ans[0] = -1;
    set<two> st;
    st.insert(two{ans[0], 0});
    while (st.size())
    {
        int x = st.begin()->second;
        st.erase(st.begin());
        for (auto [j, id] : edg[x])
        {
            auto it = upper_bound(pos[id].begin(), pos[id].end(), ans[x]);
            if (it != pos[id].end())
            {
                if (chmin(ans[j], *it))
                {
                    st.insert(two{ans[j], j});
                }
            }
        }
    }
    if (ans[n - 1] == 1e9)
    {
        cout << "-1" << endl;
    }
    else
        cout << ans[n - 1] + 1 << endl;
    return 0;
}