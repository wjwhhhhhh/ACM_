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
const int M = 998244353;
template <class T> T qmi(T k, long long p = M - 2, long long P = M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = 1ll * res * k % P;
        k = 1ll * k * k % P;
        p >>= 1;
    }
    return res % P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 A, B;
    cin >> A >> B;
    i64 re = A;
    if (B == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    vector<__int128> has, cnt;
    for (int i = 2; i <= A / i; i++)
    {
        if (A % i == 0)
        {
            cnt.push_back(0);
            has.push_back(i);
            while (A % i == 0)
            {
                cnt.back()++;
                A /= i;
            }
        }
    }
    if (A != 1)
    {
        cnt.push_back(1);
        has.push_back(A);
    }
    __int128 si = 1;
    i64 Re = B;
    i64 res = 0;
    for (int i = 0; i < cnt.size(); i++)
    {
        si = si * ((cnt[i] * B + 1ll) % M) % M;
    }
    if (Re % 2 == 0)
    {
        si = (si - 1 + M) % M;
        si = B % M * si % M * qmi(2);
        si = (si + Re / 2) % M;
    }
    else if ((i64)sqrt(re) * (i64)sqrt(re) == re)
    {
        si = (si - 1 + M) % M;
        si = B % M * si % M * qmi(2);
        si = (si + Re / 2) % M;
    }
    else
    {
        si = B % M * si % M * qmi(2) % M;
    }
    cout << (i64)si << endl;
    return 0;
}