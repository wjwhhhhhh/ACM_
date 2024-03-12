#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
std::vector<int> minp, primes;
const int N = 4e4 + 10;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes)
        {
            if (i * p > n)
            {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i])
            {
                break;
            }
        }
    }
}
void solves()
{
    int tem;
    cin >> tem;
    if (tem == 1 || tem == 4)
    {
        cout << tem << '\n';
        return;
    }
    bool fl = false;
    int ans = 0;
    for (auto i : primes)
    {
        // cout << i << ' ';
        if (i > tem)
            break;
        ans = i;
        if (tem % i == 0)
            fl = true;
    }
    if (fl)
        cout << ans << '\n';
    else
        cout << tem << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(N);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--)
    {
        solves();
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}