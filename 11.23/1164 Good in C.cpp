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
struct cha
{
    char ch[7][5];
};
void read(cha ch)
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
            cin >> ch.ch[i][j];
}
string a="hello";
string b="world";
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<cha> tr(26);
    for(int i=0;i<26;i++)read(tr[i]);
    for(int i=0;j<7;j++)
    {
        for(int i=1;i<)
    }
    return 0;
}