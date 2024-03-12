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
const int M = 1e9 + 7;
void solves()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    long long ans = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < i && a[j] <= b[i])
            j++;
        if (a[j] <= b[i])
        {
            cout << "0" << '\n';
            return;
        }
        if (i == j)
            continue;
        ans = ans * (i - j + 1) % M;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
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