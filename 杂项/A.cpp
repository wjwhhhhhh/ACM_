#include <cstdio>
#include <iostream>
#define rint register int
using namespace std;
#define N 200005
int read()
{
    char c = getchar();
    int x = 0;
    while (c < '0' || c > '9')
        c = getchar();
    while ('0' <= c && c <= '9')
        x = x * 10 + (c ^ 48), c = getchar();
    return x;
}
int n, s[N], b[N], d[N], a[N], c[N];
double ans;
int main()
{
    n = read();
    ans = 2;
    ++s[1];
    --s[2]; // ans=2：根节点算1层+最下面的1层=2层
    for (rint i = 1; i <= n; ++i)
        a[d[i] = read()] = i;
    for (rint i = 1; i <= n; ++i)
        c[b[i] = read()] = i;
    for (rint i = 1; i <= n; ++i)
        d[i] = c[d[i]], b[i] = a[b[i]];
    for (rint i = 1; i < n; ++i)
        if (b[i] > b[i + 1])
            ++s[i], --s[i + 1], ++ans; // ans没有算到最下面的一层，先加上去
    for (rint i = 1; i < n; ++i)
        if (d[i] + 1 < d[i + 1])
            ++s[d[i]], --s[d[i + 1]];
    for (rint i = 1, w = 0; i < n; ++i)
        w += s[i], ans += w ? 0 : 0.5; // 第n个点后面都是空的给它分段有什么意义吗
    //    printf("%.3f\n%.3f\n%.3f",ans-0.001,ans,ans+0.001);
    //     bzoj需要输出以上ans-0.001,ans,ans+0.001（大雾）
    printf("%.3f", ans);
    return 0;
}