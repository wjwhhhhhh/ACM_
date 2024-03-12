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
void solve()
{
    int n;
    cin >> n;
    vector<int> fa(n);
    vector<int> col(n);
    string tem;
    cin >> tem;
    for (int i = 0; i < n; i++)
        col[i] = (tem[i] == '1');
    for (int i = 0; i < n; i++)
        cin >> fa[i], fa[i]--;
    vector<int> deg(n);
    for (int i = 0; i < n; i++)
        deg[fa[i]]++;
    vector<int> ans, st(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        auto x = q.front();
        st[x] = true;
        q.pop();
        if (col[x] == 1)
        {
            ans.push_back(x);
            col[x] = 0;
            col[fa[x]] = !col[fa[x]];
        }
        deg[fa[x]]--;
        if (deg[fa[x]] == 0)
            q.push(fa[x]);
    }
    auto get = [&](deque<int> &all) {
        vector<int> tem;
        int last = 0;
        for (int i = 0; i < all.size(); i++)
        {
            if (col[all[i]] == 1)
            {
                if (last == 0)
                {
                    tem.push_back(all[i]);
                    last = 1;
                }
                else
                {
                    last = 0;
                }
            }
            else if (last == 1)
                tem.push_back(all[i]);
        }
        return tem;
    };
    for (int i = 0; i < n; i++)
    {
        if (st[i])
            continue;
        deque<int> all;
        int ing = i;
        int si = 0;
        all.push_back(ing);
        st[ing] = true;
        si += (col[ing] == 1);
        ing = fa[ing];
        while (ing != i)
        {
            all.push_back(ing);
            st[ing] = true;
            si += (col[ing] == 1);
            ing = fa[ing];
        }
        if (si % 2 != 0)
        {
            cout << "-1\n";
            return;
        }
        if (si == 0)
            continue;
        auto t1 = get(all);
        while (col[all.front()] != 1)
        {
            all.push_back(all.front());
            all.pop_front();
        }
        all.push_back(all.front());
        all.pop_front();
        auto t2 = get(all);
        if (t1.size() > t2.size())
        {
            for (auto t : t2)
                ans.push_back(t);
        }
        else
        {
            for (auto t : t1)
                ans.push_back(t);
        }
    }
    cout << ans.size() << "\n";
    for (auto c : ans)
        cout << c + 1 << " ";
    cout << '\n';
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