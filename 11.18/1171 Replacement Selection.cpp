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
using py = pair<int, int>;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> ans(n);
    priority_queue<py, vector<py>, greater<py>> st;
    for (int i = 0; i < m; i++)
        st.push({0, a[i]});
    for (int i = m; i < n; i++)
    {
        auto [x, y] = st.top();
        // cout << x << " " << y << endl;
        st.pop();
        ans[x].push_back(y);
        if (a[i] >= y)
            st.push(py{x, a[i]});
        else
            st.push({x + 1, a[i]});
    }
    while (st.size())
    {
        auto [x, y] = st.top();
        st.pop();
        ans[x].push_back(y);
    }
    for (int i = 0; i < n; i++)
    {
        if (ans.size() == 0)
            break;
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " \n"[j + 1 == ans[i].size()];
        }
    }
    return 0;
}