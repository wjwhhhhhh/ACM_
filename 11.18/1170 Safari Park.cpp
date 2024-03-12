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
const int N = 510;
int g[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = 1;
    }
    int t;
    vector<int> a(n);
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        set<int> all;
        for (int i = 0; i < n; i++)
            all.insert(a[i]);
        if (all.size() < k)
        {
            cout << "Error: Too few species." << endl;
        }
        else if (all.size() > k)
        {
            cout << "Error: Too many species." << endl;
        }
        else
        {
            bool fl = true;
            for (int i = 1; i <= n && fl; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (a[i] == a[j] && g[i][j])
                    {
                        fl = false;
                        break;
                    }
                }
            }
            if (fl)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}