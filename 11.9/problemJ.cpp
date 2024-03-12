#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin>>a;
    int n=a.size();
    SAM sa(a.size());
    for(int i=0;i<n;i++)sa.extend(a[i]);
    vector<int> siz(sa.sz);
    vector<vector<int>> edg(sa.sz);
    for(int i=1;i<sa.sz;i++)
    {
        edg[sa.st[i].link].push_back(i);
        siz[i]=sa.st[i].len-sa.st[sa.st[i].link].len;
    }
    function<void(int)>dfs=[&](int u)
    {
        for(auto c:edg[u])
        {
            dfs(c);
            siz[u]
        }
    }
    int m;
    cin>>m;
    vector<int>q(m);
    fir(i,0,m)cin>>q[i];
    return 0;
}