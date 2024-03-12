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
template <class T> struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    Tree_array(vector<T> a)
    {
        int n = a.size();
        init(n + 1);
        for (int i = 1; i < n; i++)
            insert(i, a[i]);
    }
    void init(int n)
    {
        maxx = n;
        tr.resize(n + 1);
    }
    void insert(int x, T c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    T ask(int x)
    {
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            op(res, tr[i]);
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    virtual void op(T &x, T c)
    {
        x += c;
    }
};
const int N = 1e6 + 3;
set<int> s[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    Tree_array<int> tr(N);
    cin >> n;
    vector<int> a(n + 1);
    vector<int> ans(n + 1);
    map<int, int> mp;
    int ing = 0;
    vector<pair<char, int>> has;
    for (int i = 0; i < n; i++)
    {
        char opt;
        cin >> opt;
        if (opt == '+')
        {
            int b;
            cin >> b;
            ing++;
            int v = a[ing];
            if (v != 0)
            {
                if (!s[v].empty())
                {
                    tr.insert(*s[v].begin(), -1);
                    s[v].erase(ing);
                }
                if (!s[v].empty())
                {
                    tr.insert(*s[v].begin(), 1);
                }
            }
            has.push_back({opt, v});
            v = b;
            a[ing] = b;
            if (!s[v].empty())
            {
                tr.insert(*s[v].begin(), -1);
            }
            s[v].insert(ing);
            if (!s[v].empty())
            {
                tr.insert(*s[v].begin(), 1);
            }
        }
        else if (opt == '-')
        {
            int b;
            cin >> b;
            has.push_back({opt, b});
            ing -= b;
        }
        else if (opt == '!')
        {
            auto get = has.back();
            has.pop_back();
            if (get.first == '-')
            {
                ing += get.second;
            }
            else
            {
                int v = a[ing];
                if (!s[v].empty())
                {
                    tr.insert(*s[v].begin(), -1);
                }
                s[v].erase(ing);
                if (!s[v].empty())
                {
                    tr.insert(*s[v].begin(), 1);
                }
                v = get.second;
                a[ing] = v;
                if (v != 0)
                {
                    if (!s[v].empty())
                    {
                        tr.insert(*s[v].begin(), -1);
                    }
                    s[v].insert(ing);
                    if (!s[v].empty())
                    {
                        tr.insert(*s[v].begin(), 1);
                    }
                }
                ing--;
            }
        }
        else
            cout << tr.ask(ing) << endl;
    }
    return 0;
}
/*
0
1
2
3
3
2
4
1
1
5+*/