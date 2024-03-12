#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SAM
{
    struct state
    {
        int len, link;
        int next[26];
    };
    vector<state> st;
    vector<int> cnt;
    int sz, last;
    SAM(int n)
    {
        cnt.resize(2 * n);
        st.resize(2 * n);
        init();
    }
    void init()
    {
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;
        last = 0;
    }
    void extend(int ch)
    {
        int c = ch;
        cnt[sz] = 1;
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next[c])
        {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1)
        {
            st[cur].link = 0;
        }
        else
        {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
            {
                st[cur].link = q;
            }
            else
            {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                for (int i = 0; i < 26; i++)
                    st[clone].next[i] = st[q].next[i];
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c] == q)
                {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    int query()
    {
        int ans = 0;
        vector<vector<int>> edge(sz);
        for (int i = 1; i < sz; i++)
            edge[st[i].link].push_back(i);
        function<void(int)> dfs = [&](int u) {
            // cout << u << ' ';
            for (auto x : edge[u])
            {
                dfs(x);
                cnt[u] += cnt[x];
            }
            // cout << endl;
            if (cnt[u] == 1)
                ans = max(ans, cnt[u] * st[u].len), cerr << st[st[u].link].len << st[u].len;
        };
        dfs(0);

        return ans;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SAM sam(n);
    for (int i = 0; i < n; i++)
        sam.extend(a[i]);
    cout << sam.query() << endl;
    // cout << "ok" << endl;
}
signed main()
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