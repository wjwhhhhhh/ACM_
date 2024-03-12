#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl;
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
    vector<i64> cnt;
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
    void extend(char ch)
    {
        int c = ch - 'a';
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        cnt[cur] = 1;
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

    void query(int t)
    {
        int ans = 0;
        vector<vector<int>> edge(sz);
        vector<i64> sum(sz);
        if (t == 1)
        {
            dfs(0);
        }
        else
        {
            for (int i = 0; i < sz; i++)
                sum[i] = cnt[i] = 1;
        }
        sum[0] = cnt[0] = 0;
        vector<int> v(sz);
        function<void(int)> dfs2 = [&](int u) {
            if (v[u])
                return;
            v[u] = true;
            for (int j = 0; j < 26; j++)
            {
                if (st[u].next[j])
                {
                    dfs2(st[u].next[j]);
                    sum[u] += sum[st[u].next[j]];
                }
            }
        };
        dfs2(0);
        int k;
        cin >> k;
        if (sum[0] < k)
        {
            cout << -1 << endl;
            return;
        }
        function<void(int, int)> print = [&](int k, int u) {
            if (k <= cnt[u])
                return;
            k -= cnt[u];
            for (int i = 0; i < 26; i++)
            {
                if (st[u].next[i])
                {
                    if (sum[st[u].next[i]] >= k)
                    {
                        cout << char(i + 'a');
                        print(k, st[u].next[i]);
                        return;
                    }
                    else
                        k -= sum[st[u].next[i]];
                }
            }
        };
        print(k, 0);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    SAM sam(a.size() + 10);
    for (auto x : a)
        sam.extend(x);
    int t;
    cin >> t;
    sam.query(t);
    return 0;
}