#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
using namespace std;
const int N = 2e5 + 10, M = 30;
typedef pair<int, int> PII;
int son[N * M][2], cnt[N * M], ma[N * M];
int idx = 0;
int sum = 0;
inline int read()
{
    char c = getchar();
    int x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            s = -1;
        c = getchar();
    } // 是符号
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    } // 是数字
    return x * s;
}
vector<int> st;
void pushup(int &u1, int tem)
{
    while (son[tem][1] || son[tem][0])
    {
        if (cnt[son[tem][0]] == 1)
        {
            u1 = u1 * 2 + 0;
            tem = son[tem][0];
        }
        else if (cnt[son[tem][1]] == 1)
        {
            u1 = u1 * 2 + 1;
            tem = son[tem][1];
        }
    }
}
void update()
{
    if (sum <= 1)
        return;
    int l = st.size() - 1;
    while (cnt[st[l]] < 2)
        l--;
    if (l == st.size() - 1)
    {
        ma[st[l]] = 0;
        l--;
    }
    else if (cnt[son[st[l]][1]] == 1 && cnt[son[st[l]][0]] == 1)
    {
        int u1 = 0, u2 = 1;
        pushup(u1, son[st[l]][0]);
        pushup(u2, son[st[l]][1]);
        ma[st[l]] = (u1 ^ u2);
        l--;
    }
    while (l >= 0)
    {
        int t = st[l];
        ma[t] = 0x3f3f3f3f;
        if (son[t][1] && cnt[son[t][1]] > 1)
            ma[t] = min(ma[t], ma[son[t][1]]);
        if (son[t][0] && cnt[son[t][0]] > 1)
            ma[t] = min(ma[t], ma[son[t][0]]);
        l--;
    }
}
void in(int k)
{
    int p = 0;
    st.clear();
    st.push_back(0);
    for (int i = M - 1; i >= 0; i--)
    {
        int tem = k >> i & 1;
        if (!son[p][tem])
            son[p][tem] = ++idx;
        cnt[p]++;
        p = son[p][tem];
        st.push_back(p);
    }
    cnt[p]++;
    update();
}
void dele(int k)
{
    int p = 0;
    st.clear();
    st.push_back(0);
    for (int i = M - 1; i >= 0; i--)
    {
        int tem = k >> i & 1;
        cnt[p]--;
        p = son[p][tem];
        st.push_back(p);
    }
    cnt[p]--;
    update();
}
int quety()
{
    return ma[0];
}
int main()
{
    // freopen("test.txt", "r", stdin);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        string tem;
        int k;
        cin >> tem;
        if (tem == "ADD")
        {

            sum++;
            cin >> k;
            in(k);
        }
        else if (tem == "DEL")
        {
            sum--;
            cin >> k;
            dele(k);
        }
        else
        {
            cout << quety() << endl;
        }
    }
    return 0;
}