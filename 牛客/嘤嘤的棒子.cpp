#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define endl "\n"

#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
const int N = 1e6 + 10;
const int M = 15, maxn = (1 << 15) - 1;
string s;
int ans = 0x3f3f3f3f, n, k, sum = 0;
int lowbit(int x)
{
    return x & -x;
}
//   价值
int cnt[M * 2][M * 2], sum1[maxn + 1][M * 2], sum2[maxn + 1][M * 2];
int mp[150]; // 哈希
void dfs(int u, int sum, int sta, int pre)
{
    if (u == 0)
    {
        ans = min(sum, ans);
        return;
    }
    for (int i = pre; i + u <= 30; i++)
    {
        int tem = sum;
        int st1 = sta & maxn, st2 = sta >> 15;
        tem = sum - sum1[maxn][i] - sum2[maxn][i] + sum1[st1][i] + sum2[st2][i];
        dfs(u - 1, tem, sta + (1 << i), i + 1);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    if (k >= M * 2 - 1)
    {
        cout << 0 << endl;
        return 0;
    }
    string str(26, '0');
    iota(str.begin(), str.end(), 'a');
    str += ",.!?";
    for (int i = 0; i < 30; i++)
        mp[str[i]] = i;
    for (int i = 1, j = n; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            cnt[mp[s[i]]][mp[s[j]]] = ++cnt[mp[s[j]]][mp[s[i]]];
            sum++;
        }
    }
    fir(i, 1, maxn)
    {
        int x = __lg(lowbit(i));
        fir(j, 0, 2 * M - 1)
        {
            sum1[i][j] = sum1[i - (1 << x)][j] + cnt[x][j];
        }
    }
    fir(i, 1, maxn)
    {
        int x = __lg(lowbit(i));
        fir(j, 0, 2 * M - 1)
        {
            sum2[i][j] = sum2[i - (1 << x)][j] + cnt[x + 15][j];
        }
    }
    dfs(k, sum, 0, 0);
    cout << ans << endl;
    return 0;
}