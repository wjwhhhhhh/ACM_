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
const int N = 1010;
int col[N][N];
i64 ans = 0;
map<int, vector<int>> x;
void get()
{
    for (auto [x, cnt] : x)
    {
        sort(cnt.begin(), cnt.end());
        int len = cnt.size();
        vector<i64> s(len + 1, 0);
        for (int i = 1; i <= len; i++)
        {
            s[i] = s[i - 1] + cnt[i - 1];
        }
        for (int i = 1; i <= len; i++)
        {
            // cout << s[i - 1] << endl;
            ans += (1ll * i - 1) * cnt[i - 1] - s[i - 1] - (1ll * len - i) * cnt[i - 1] + (s[len] - s[i]);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> col[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            x[col[i][j]].push_back(i);
        }
    get();
    x.clear();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            x[col[i][j]].push_back(j);
        }
    get();
    cout << ans << endl;
    return 0;
}