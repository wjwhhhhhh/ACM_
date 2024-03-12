#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
struct SAM
{
    struct state
    {
        int len, link;
        int next[26];
    };
    vector<state> st;
    int sz, last;
    SAM(int n)
    {
        st.resize(2 * n);
        init();
    }
    void init()·
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
                st[q].link = st[cur].link = clone;
                while (p != -1 && st[p].next[c] == q)
                {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }

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
            //cout << endl;
            if (cnt[u] > 1)
                ans = max(ans, cnt[u] * st[u].len);
        };
        dfs(0);

        return ans;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 10;
    std::string s;
    s.resize(n);
    cout << s << "hj" << endl;
    // freopen("test.txt", "r", stdin);

    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}