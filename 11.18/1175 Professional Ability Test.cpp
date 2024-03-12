#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using three = array<int, 3>;
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
py add(py x, py y)
{
    return py(x.first + y.first, x.second + y.second);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<vector<three>> edg(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edg[b].push_back(three{a, c, d});
    }
    bool fl = true;
    vector<string> ans;
    int t;
    cin >> t;
    while (t--)
    {
        int tr;
        cin >> tr;
        if (edg[tr].size() == 0)
        {
            ans.push_back("You may take test " + to_string(tr) + " directly.");
            continue;
        }
        vector<int> v(n), in(n);
        function<bool(int)> dfs = [&](int u) {
            in[u] = v[u] = true;
            for (auto [c, x, y] : edg[u])
            {
                if (in[c])
                    return true;
                else if (!v[c] && dfs(c))
                    return true;
            }
            in[u] = false;
            return false;
        };
        if (dfs(tr))
        {
            ans.push_back("Error.");
            fl = false;
            continue;
        }
        vector<py> dist(n, py{1e9, 0});
        fill(v.begin(), v.end(), 0);
        priority_queue<pair<py, int>, vector<pair<py, int>>, greater<pair<py, int>>> st;
        dist[tr] = {0, 0};
        st.push({dist[tr], tr});
        vector<int> fr(n, -1);
        while (st.size())
        {
            auto c = st.top().second;
            st.pop();
            if (v[c])
                continue;
            v[c] = true;
            for (auto [to, x, y] : edg[c])
            {
                if (add(dist[c], py{x, -y}) < dist[to])
                {
                    dist[to] = add(dist[c], py{x, -y});
                    fr[to] = c;
                    st.push({dist[to], to});
                }
            }
        }
        py an{1e9, 0};
        int from;
        for (int i = 0; i < n; i++)
        {
            if (edg[i].size() == 0)
            {
                if (chmin(an, dist[i]))
                {
                    from = i;
                }
            }
        }
        vector<int> cnt;
        while (from != tr)
        {
            cnt.push_back(from);
            from = fr[from];
        }
        cnt.push_back(tr);
        ans.push_back(to_string(cnt[0]));
        for (int i = 1; i < cnt.size(); i++)
        {
            ans.back() += "->";
            ans.back() += to_string(cnt[i]);
        }
    }
    if (fl)
    {
        cout << "Okay." << endl;
    }
    else
        cout << "Impossible." << endl;
    for (auto c : ans)
        cout << c << endl;
    return 0;
}