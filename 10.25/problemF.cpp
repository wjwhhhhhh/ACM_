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
using p = array<int, 2>;
bool equal(p x, p y)
{
    return min(x[0], x[1]) == min(y[0], y[1]) && max(x[0], x[1]) == max(y[0], y[1]);
}
vector<int> a[8];
void init()
{
    a[1] = {2, 3};
    a[2] = {1, 4};
    a[3] = {1, 4};
    a[4] = {2, 3, 5, 6};
    a[5] = {4, 7};
    a[6] = {4, 7};
    a[7] = {5, 6};
}

void solve()
{
    p s, t;
    cin >> s[0] >> s[1] >> t[0] >> t[1];
    set<p> has;
    auto in = [&](p x) {
        if (x[0] > x[1])
            swap(x[0], x[1]);
        if (has.find(x) != has.end())
            return false;
        else
        {
            has.insert(x);
            return true;
        }
    };
    bool fl = true;
    int ans = -1;
    queue<p> q;
    q.push(s);
    while (fl)
    {
        int si = q.size();
        while (si--)
        {
            auto x = q.front();
            q.pop();
            if (equal(x, t))
            {
                fl = false;
                break;
            }
            for (auto c : a[x[0]])
            {
                if (c == x[1])
                    continue;
                if (in(p{c, x[1]}))
                {
                    q.push(p{c, x[1]});
                }
            }
            for (auto c : a[x[1]])
            {
                if (c == x[0])
                    continue;
                if (in(p{x[0], c}))
                {
                    // cerr << x[0] << " " << c << endl;
                    q.push(p{x[0], c});
                }
            }
        }
        ans++;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    init();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}