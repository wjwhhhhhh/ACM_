#include <bits/stdc++.h>
using namespace std;
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
    void extend(char ch)
    {
        int c = ch - 'a';
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
        return st[last].len - st[st[last].link].len;
    }
};
void solve()
{
    string a;
    cin >> a;
    int n = a.size();
    int q;
    cin >> q;
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        SAM sam(n);
        int res = 0;
        for (int j = i; j < n; j++)
        {
            sam.extend(a[j]);
            res += sam.query();
            // cout << sam.query() << endl;
            ans[i].push_back(res);
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ans[l - 1][r - l] << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}