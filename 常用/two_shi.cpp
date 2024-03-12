#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
// 699050
//838860
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string tem;
    cin >> tem;
    long long sum = 0;
    for (auto i : tem)
    {
        sum <<= 1;
        if (i == '1')
            sum += 1;
    }
    cout << sum << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}