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
string T;
int get(string &a)
{
    int ing = 0;
    for (auto c : a)
    {
        if (ing < T.size() && T[ing] == c)
            ing++;
    }
    return ing;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    cin >> T;
    vector<string> all(n);
    fir(i, 0, n) cin >> all[i];
    vector<i64> cnt(T.size() + 1), s(T.size() + 1);
    fir(i, 0, n)
    {
        // cout << get(all[i]) << endl;
        cnt[get(all[i])]++;
        reverse(all[i].begin(), all[i].end());
    }
    reverse(T.begin(), T.end());
    fir(i, 0, n)
    {
        s[get(all[i])]++;
    }
    for (int i = T.size() - 1; i >= 0; i--)
    {
        s[i] += s[i + 1];
    }
    i64 ans = 0;
    for (int i = 0; i <= T.size(); i++)
    {
        ans += cnt[i] * s[(int)T.size() - i];
    }
    cout << ans << endl;
    return 0;
}