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
int ans = 0;
int idx[N];
int a[N];
make oldconfig
bool get(int l, int r)
{
    int mi = 0x3f3f3f3f, ma = 0;
    for (int i = l; i <= r; i++)
    {
        idx[a[i]]++;
        chmin(mi, a[i]);
        chmax(ma, a[i]);
    }
    ans = ma - mi;
    if (ans == 0 || ans % (r - l) != 0)
        return false;
    ans /= (r - l);
    for (int i = mi; i <= ma; i += ans)
    {
        if (idx[i] != 1)
            return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    vector<int> tem;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        i64 sum = (len + 1) * len / 2;
        if (sum >= N)
        {
            cout << "-1" << '\n';
        }
        else
        {
            if (get(l, r))
                cout << ans << '\n';
            else
                cout << "-1\n";
            for (int i = l; i <= r; i++)
            {
                idx[a[i]]--;
            }
        }
    }
    return 0;
}