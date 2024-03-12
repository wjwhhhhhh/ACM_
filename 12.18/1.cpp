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
template <class T> class Fenwick
{
  public:
    Fenwick() = default;
    Fenwick(int n, T temp = T())
    {
        this->temp = temp;
        values.resize(n, temp);
        auto f = [&](T &x, T y) {
            x += y;
            return;
        };
        func = f;
    }
    Fenwick(int n, const std::function<void(T &, T)> f, T temp = T())
    {
        this->temp = temp;
        values.resize(n, temp);
        func = f;
    }
    void add(int x, T y)
    {
        x++;
        for (int i = x; i <= values.size(); i += i & -i)
        {
            func(values[i - 1], y);
        }
        return;
    }
    T ask(int x)
    {
        x++;
        T res = temp;
        for (int i = x; i > 0; i -= i & -i)
        {
            // cerr << i << endl;
            func(res, values[i - 1]);
        }
        return res;
        // cerr << "ok" << endl;
    }

  private:
    T temp;
    std::function<void(T &, T)> func;
    std::vector<T> values;
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &c : a)
        cin >> c;
    Fenwick<int> fr(n);
    for (int i = 0; i < a.size(); i++)
    {
        fr.add(i, a[i]);
    }
    while (m--)
    {
        int fl;
        cin >> fl;
        if (fl == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            fr.add(x, y);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            cout << fr.ask(y) - fr.ask(x - 1) << endl;
        }
    }
    return 0;
}