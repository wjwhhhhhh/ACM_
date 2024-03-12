#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const int N = 2e5 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> s(2e5 + 10);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s[a]++, s[b + 1]--;
    }
    for (int i = 1; i < 2e5 + 10; i++)
        s[i] += s[i - 1];
    vector<int> ss(N);
    for (int i = 1; i < N; i++)
        if (s[i] >= k)
            ss[i] = 1;
    for (int i = 1; i < N; i++)
        ss[i] += ss[i - 1];
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << ss[b] - ss[a - 1] << endl;
    }
    return 0;
}