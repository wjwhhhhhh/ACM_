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
bool op(char a, char b)
{
    return a == b;
}
vector<int> prefix_function(string s) // 计算前缀函数
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && !op(s[i], s[j]))
            j = pi[j - 1];
        if (op(s[i], s[j]))
            j++;
        pi[i] = j;
    }
    return pi;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    auto next = prefix_function(a);
    int ing = next.back();
    vector<int> has;
    while (ing != 0)
    {
        has.push_back(ing);
        ing = next[ing - 1];
    }
    sort(has.begin(), has.end());
    has.push_back(a.size());
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        int an = min(s - 1, (int)a.size() - s);
        int l = 0, r = has.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (has[mid] > an)
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}