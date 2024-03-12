#include <bits/stdc++.h>
using namespace std;

// Start
typedef long long ll;
typedef double db;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define b(a) a.begin()
#define e(a) a.end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

// Data
const int N = 5e5;
int n;
char s[N + 7];

// SuffuxAutomaton
const int T = N << 1;
int en = 1, cnt = 1, ch[T + 7][26], fa[T + 7], dep[T + 7]; // dep即len
ll sz[T + 7], sm[T + 7];
void insert(int c)
{
    int p = en, np = en = ++cnt;
    dep[np] = dep[p] + 1;
    for (; p && !ch[p][c]; p = fa[p])
        ch[p][c] = np;
    if (!p)
        fa[np] = 1;
    else
    {
        int q = ch[p][c];
        if (dep[q] == dep[p] + 1)
            fa[np] = q;
        else
        {
            int nq = ++cnt;
            dep[nq] = dep[p] + 1;
            memcpy(ch[nq], ch[q], sizeof ch[q]);
            fa[nq] = fa[q], fa[q] = fa[np] = nq;
            for (; ch[p][c] == q; p = fa[p])
                ch[p][c] = nq;
        }
    }
    sz[np] = 1;
}
int c[T + 7], q[T + 7];
void run(int t)
{
    for (int i = 1; i <= cnt; i++)
        c[dep[i]]++;
    for (int i = 1; i <= cnt; i++)
        c[i] += c[i - 1];
    for (int i = 1; i <= cnt; i++)
        q[c[dep[i]]--] = i;
    for (int i = cnt; i >= 1; i--)
        sz[fa[q[i]]] += sz[q[i]];
    for (int i = 1; i <= cnt; i++)
        sm[i] = t ? sz[i] : (sz[i] = 1);
    sz[1] = sm[1] = 0;
    for (int i = cnt; i >= 1; i--)
        for (int c = 0; c < 26; c++)
            sm[q[i]] += sm[ch[q[i]][c]];
}
void Print(int p, int k)
{
    if (k <= sz[p])
        return;
    k -= sz[p];
    for (int c = 0; c < 26; c++)
        if (ch[p][c])
        {
            if (k > sm[ch[p][c]])
                k -= sm[ch[p][c]];
            else
                return void((putchar(c + 'a'), Print(ch[p][c], k)));
        }
}

// Main
int main()
{
    int t, k;
    scanf("%s%d%d", &s[1], &t, &k), n = strlen(&s[1]);
    for (int i = 1; i <= n; i++)
        insert(s[i] - 'a');
    run(t);
    cout << sm[1] << endl;
    if (sm[1] >= k)
        Print(1, k);
    else
        puts("-1");
    return 0;
}