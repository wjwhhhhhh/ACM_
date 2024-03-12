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
    int ans = 0;
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
        int c = ch - 'A';
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
                has.push_back(sz);
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
        ans += st[last].len - st[st[last].link].len;
    }
};
void solve()
{
    string a;
    cin >> a;
    int n = a.size();
    SAM sam(n);
    for (int i = 0; i < n; i++)
        sam.extend(a[i]), cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}