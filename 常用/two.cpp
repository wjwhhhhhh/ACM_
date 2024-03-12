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
// 64125 64307 9550
signed main()
{
    // 1001 01010 01110
    // 111110 10011 11110
    // 111110 11001 10011
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tem;
    cin >> tem;
    string te = "";
    for (int i = 0; i < 32 && tem; i++)
    {
        if (tem & 1)
            te += '1';
        else
            te += '0';
        tem >>= 1;
    }
    reverse(te.begin(), te.end());
    cout << te;
    // cout << (30285 & 13901) << endl;
    //  freopen("CON", "r", stdin);
    //  system("pause");
    return 0;
}
// 64125 64307 9550