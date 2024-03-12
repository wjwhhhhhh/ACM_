#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct zuo
{
    double x, y;
} w[N];
bool cmp(zuo x, zuo y)
{
    return x.x < y.x;
}
bool cmp1(zuo x, zuo y)
{
    return x.y < y.y;
}
double get(zuo a, zuo b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
zuo q[N];
double divde(int l, int r)
{
    int d = 0x3f3f3f3f;
    if (l == r)
        return d;
    else if (l + 1 == r)
        return get(w[l], w[r]);
    int mid = l + r >> 1;
    double d1 = divde(l, mid);
    double d2 = divde(mid + 1, r);
    double ans = min(d1, d2);
    int k = 0;
    for (int i = l; i <= r; i++)
    {
        if (fabs(w[i].x - w[mid].x) <= ans)
            q[++k] = w[i];
    }
    sort(q + 1, q + 1 + k, cmp1);
    for (int i = 1; i <= k; i++)
    {
        for (int j = i + 1; j <= k && q[j].y - q[i].y <= ans; j++)
        {
            ans = min(ans, get(q[i], q[j]));
        }
    }
    return ans;
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int si = 0;
    cin >> si;
    for (int i = 1; i <= si; i++)
    {
        cin >> w[i].x >> w[i].y;
    }
    sort(w + 1, w + 1 + si, cmp);
    printf("%.4lf", divde(1, si));
    return 0;
}