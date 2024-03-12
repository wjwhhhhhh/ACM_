#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s)//对于个长度为 n 的字符串 s。定义函数 z[i] 表示 s 和 s[i,n-1]（即以 s[i] 开头的后缀）的最长公
//共前缀（LCP）的长度。z 被称为 s 的 Z 函数。特别地，z[0] = 0。
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r && z[i - l] < r - i + 1)
        {
            z[i] = z[i - l];
        }
        else
        {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
        }
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}