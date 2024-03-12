#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SAM
{
    struct state
    {
        int len, link;
        map<int, int> next;
    };
    vector<state> st;
    // vector<int> cnt;
    i64 ans = 0;
    int sz, last;
    SAM(int n)
    {
        // cnt.resize(2 * n);
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

                st[clone].next = st[q].next;
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
        ans += st[cur].len - st[st[cur].link].len;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    SAM sam(n);
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        sam.extend(tem);
        cout << sam.ans << '\n';
    }
    return 0;
}