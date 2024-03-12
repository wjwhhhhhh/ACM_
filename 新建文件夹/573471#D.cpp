#include <bits/stdc++.h>
const int bug = false;
#define dug(x)                                                                                                         \
    if (bug)                                                                                                           \
    cerr << "死了吧小丑" << x << endl
#define fir(i, a, b) for (int i = a; i < b; i++)
#define far(a, b) for (auto a : b)
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
template <class T> T min(T a, T b)
{
    return a > b ? b : a;
}
template <class T> T max(T a, T b)
{
    return a < b ? b : a;
}
map<pair<array<int, 20>, pair<int, int>>, string> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a;
    cin >> a;
    array<int, 20> st;
    string ans = "", res = "";
    vector<int> s(n + 1), q;
    for (int i = n - 1; i >= 0; i--)
    {
        s[i] = s[i + 1] | (1 << a[i] - 'a');
    }
    q = s;
    vector<int> cn(1 << 20);
    function<void(int, int, int ing)> find = [&](int u, int res, int ing) {
        if (u == 20)
        {
            cn[ing] = res;
            return;
        }
        find(u + 1, res + 1, ing + (1 << u));
        find(u + 1, res, ing);
    };
    find(0, 0, 0);
    function<string(int)> dfs = [&](int l) -> string {
        if (l >= n || q[l] == 0)
        {
            return "";
        }
        if (mp.find({st, {l, q[l]}}) != mp.end())
        {
            return mp[{st, {l, q[l]}}];
        }
        array<int, 20> has = {};
        array<int, 20> si = {};
        fill(has.begin(), has.end(), -1);
        for (int i = l; i < n; i++)
        {
            if (st[a[i] - 'a'])
                continue;
            if (q[i] != q[l])
                break;
            has[a[i] - 'a'] = i;
            si[a[i] - 'a']++;
        }
        int cnt = cn[q[l]];
        vector<int> o(20);
        iota(o.begin(), o.end(), 0);
        sort(o.begin(), o.end(), [&](int x, int y) { return si[x] > si[y]; });
        string res = "";
        for (int z = 0; z < 20; z++)
        {
            int i = o[z];
            if (si[i] != si[o[0]])
                continue;
            if (st[i] || has[i] == -1)
                continue;
            st[i] = true;
            for (int j = n - 1; j >= has[i] + 1; j--)
            {
                if (st[a[j] - 'a'])
                    q[j] = q[j + 1];
                else
                    q[j] = q[j + 1] | (1 << a[j] - 'a');
            }
            string tem(si[i], char(cnt + 'a' - 1));
            chkmax(res, tem + dfs(has[i] + 1));
            st[i] = false;
            for (int j = n - 1; j >= has[i] + 1; j--)
            {
                if (st[a[j] - 'a'])
                    q[j] = q[j + 1];
                else
                    q[j] = q[j + 1] | (1 << a[j] - 'a');
            }
        }
    };
    dfs(0);
    cout << mp[{st, {0, q[0]}}] << endl;
    return 0;
}