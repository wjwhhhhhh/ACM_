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
const int N = 5e5 + 10;
int a[N];
int ci = 0;
int cao(int *a, int l, int r)
{
    int tr = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (1)
    {
        do
        {
            i++;
        } while (a[i] < tr);
        do
        {
            j--;
        } while (a[j] > tr);
        if (i >= j)
            return j;
        else
            swap(a[i], a[j]), ci++;
    }
}
void quick_sort(int *a, int l, int r)
{
    if (l >= 0 && r >= 0 && l < r)
    {
        int q = cao(a, l, r);
        quick_sort(a, l, q);
        quick_sort(a, q + 1, r);
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ci = 0;
    quick_sort(a, 1, n);
    cout << ci << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}