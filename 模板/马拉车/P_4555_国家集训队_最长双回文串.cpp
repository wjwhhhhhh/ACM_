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
void Manacher(vector<int> &d1, vector<int> &d2,
              string s) // 二者也表示了以位置 i 为中心的最长回文串的半径长度（半径长度 d_1[i]，d_2[i] 均为从位置 i
                        // 到回文串最右端位置包含的字符个数）。
{
    int n = s.size();
    d1.resize(n), d2.resize(n);
    fill(d1.begin(), d1.end(), 0), fill(d2.begin(), d2.end(), 0);
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
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    string tem;
    cin >> tem;
    int n = tem.size();
    vector<int> d1, d2;
    Manacher(d1, d2, tem);
    vector<int> left(n + 5), right(n + 5);
    for (int i = 0; i < d1.size(); i++)
    {
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}