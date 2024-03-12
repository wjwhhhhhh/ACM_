#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
    int n;
    cin >> n;
    vector<int> du(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        du[a[i]]++;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] == 0)
            q.push(i);
    }
    set<int> has, jue;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (jue.find(x) == jue.end())
        {
            ans.push_back(x);
            has.insert(x);
            if (jue.find(a[x]) == jue.end())
                q.push(a[x]);
            jue.insert(a[x]);
        }
        else
        {
            du[a[x]]--;
            if (du[a[x]] == 0)
                q.push(a[x]);
        }
    }
    // cout << ans.size() << endl;
    vector<int> st(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!st[i] && has.find(i) == has.end() && jue.find(i) == jue.end())
        {
            vector<int> all;
            st[i] = true;
            int ing = a[i];
            all.push_back(i);
            while (ing != i)
            {
                st[ing] = true;
                all.push_back(ing);
                ing = a[ing];
            }
            if (all.size() & 1)
            {
                cout << "-1" << endl;
                return 0;
            }
            for (int i = 0; i < all.size(); i += 2)
            {
                ans.push_back(all[i]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << a[ans[i]] << " ";
    }
    return 0;
}