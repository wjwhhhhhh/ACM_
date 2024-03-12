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
const int N = 6;
vector<vector<string>> w(N);
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> o(n);
    iota(a.begin(), a.end(), 0);
    shuffle(a.begin(), a.end(), rnd);
    for (int i = 1; i < n; i++)
        cout << (a[i] ^ a[i - 1]) << " ";
    return 0;
}