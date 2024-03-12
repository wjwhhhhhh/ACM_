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
const int N = 2e5 + 10, K = sqrt(N);
int cnt[N];
int val[N];
int ku[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i <= n; i++)
    {
        if (val[i] >= N)
            continue;
        cnt[val[i]]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (cnt[i])
            ku[i / K]++;
    }
    while (q--)
    {
        int t, x;
        cin >> t >> x;
        if (val[t] < N)
        {
            cnt[val[t]]--;
            if (cnt[val[t]] == 0)
                ku[val[t] / K]--;
        }
        val[t] = x;
        if (x < N)
        {
            cnt[x]++;
            if (cnt[x] == 1)
                ku[x / K]++;
        }
        int ing = 0;
        while (ku[ing] == K)
        {
            ing++;
        }
        ing *= K;
        while (cnt[ing] != 0)
        {
            ing++;
        }
        cout << ing << '\n';
    }
    return 0;
}