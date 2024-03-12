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
int find(vector<int> &a, int wei)
{
    int si = 1 << wei;
    int a0 = 0, a1 = 0;
    for (auto c : a)
    {
        if (c & si)
            a1++;
        else
            a0++;
    }
    if (a1 > a0)
        return 1;
    else
        return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n - 1);
    fir(i, 0, n - 1) cin >> a[i];
    fir(i, 1, n - 1) a[i] ^= a[i - 1];
    int idx = -1;
    int tem = n - 1;
    while (tem)
    {
        idx++;
        tem >>= 1;
    }
    vector<int> b = a;
    int a0 = 0;
    for (int j = idx; j >= 0; j--)
    {
        int si = find(b, j);
        a0 += si << j;
        // vector<int> tem;
        // if (si == 1)
        // {
        //     for (auto c : b)
        //     {
        //         if (c & 1 << j)
        //             tem.push_back(c);
        //     }
        // }
        // else
        // {
        //     for (auto c : b)
        //     {
        //         if (!(c & 1 << j))
        //             tem.push_back(c);
        //     }
        // }
        // b = tem;
    }
    cout << endl;
    cout << a0 << " ";
    for (int i = 0; i < n - 1; i++)
    {
        // cout << a[i] << " ";
        cout << (a0 ^ a[i]) << " ";
    }
    return 0;
}