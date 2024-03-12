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
const int N = 1e5 + 10;
int has[N], need[N];
void in(int x)
{
    if (x >= 0)
        need[x] = true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int a, b;
    cin >> a >> b;
    has[a] = has[b] = true;
    in(a - b), in(b - a);
    set<int> ans;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        ans.insert(i);
    vector<vector<int>> cnt(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> cnt[i][j];
    vector<int> all;
    all.push_back(a);
    all.push_back(b);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans.find(j) == ans.end())
                continue;
            if (!need[cnt[j][i]] || has[cnt[j][i]])
            {
                ans.erase(j);
                cout << "Round #" << to_string(i + 1) << ": " << to_string(j + 1) << " is out." << '\n';
            }
            else
            {
                for (auto c : all)
                {
                    in(c - cnt[j][i]);
                    in(cnt[j][i] - c);
                }
                all.push_back(cnt[j][i]);
                has[cnt[j][i]] = true;
            }
        }
    }
    if (ans.size() == 0)
        cout << "No winner." << '\n';
    else
    {
        cout << "Winner(s):";
        for (auto c : ans)
            cout << " " << c + 1;
    }
    return 0;
}