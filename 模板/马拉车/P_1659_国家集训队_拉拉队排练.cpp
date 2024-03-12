#include <bits/stdc++.h>
using namespace std
// #define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
    // #define read(x) scanf("%d",&x)
    typedef long long LL;
typedef std::pair<int, int> PII;
void Manacher(vector<int> &d1,
              string s) // 二者也表示了以位置 i 为中心的最长回文串的半径长度（半径长度 d_1[i]，d_2[i] 均为从位置 i
                        // 到回文串最右端位置包含的字符个数）。
{
    int n = s.size();
    d1.resize(n);
    fill(d1.begin(), d1.end(), 0);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
}
const int M = 19930726;

vector<int> d1;
long long n, k;
bool check(int x)
{
    if (x == 0)
        return true;
    long long ans = 0;
    for (auto i : d1)
    {
        if (i >= x)
            ans += (i - x + 1);
    }
    return ans >= k;
}
long long qmi(long long k, long long p, long long M)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("P1659_9.in", "r", stdin);

    cin >> n >> k;
    string s;
    cin >> s;
    Manacher(d1, s);
    sort(d1.begin(), d1.end());
    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (l == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        long long ans = 1;
        // cout << l;
        vector<long long> fac(n + 5);
        fac[l] = 1;
        for (int i = l + 1; i <= n; i++)
            fac[i] = fac[i - 1] * (2 * i - 1) % M;
        for (auto i : d1)
        {
            if (i <= l)
                continue;
            ans = ans * fac[i] % M;
            k -= i - l;
        }
        if (k)
            ans = ans * qmi(2 * l - 1, k, M) % M;
        cout << ans << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}