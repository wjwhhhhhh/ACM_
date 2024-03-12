#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a = "tourist 3858 ksun48 3679 Benq 3658 Um_nik 3648 apiad 3638 Stonefeang 3630 ecnerwala 3613 mnbvmar 3555 "
               "newbiedmy 3516 semiexp 3481 ";
    string x, y;
    int id = 0;
    map<string, int> mp;
    auto get = [&](string a) {
        int ing = 0;
        for (int i = 0; i < a.size(); i++)
            ing = ing * 10 + a[i] - '0';
        return ing;
    };
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ')
        {

            if (id % 2 != 0)
            {

                mp[x] = get(y);
                x = "", y = "";
            }
            id++;
        }
        else if (id % 2 == 0)
            x += a[i];
        else
            y += a[i];
    }
    string t;
    cin >> t;
    cout << mp[t] << endl;
    return 0;
}