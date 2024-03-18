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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    vector<string> all;
    string a;
    int n;
    cin >> n;
    cin >> a;
    if (n == 1)
    {
        cout << a << endl;
        return 0;
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            all.push_back(a.substr(0, i + 1) + a.substr(j, a.size() - j));
            all.push_back(a.substr(j, a.size() - j));
        }
        all.push_back(a.substr(0, i + 1));
    }
    string ans = "";
    for (auto &c : all)
    {
        string tem = "";
        tem += char(1 + 'z');
        // cout << tem << endl;
        for (int i = 0; i < c.size(); i++)
        {
            string temp = c.substr(0, i + 1);
            chmin(tem, temp);
            temp = c.substr(i, c.size() - i);
            chmin(tem, temp);
        }

        chmax(ans, tem);
    }
    std::string s = '{';
    std::cerr << s << "\n";
    cout << ans << endl;
    return 0;
}