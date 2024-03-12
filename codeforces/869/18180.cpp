#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define x first
#define y second 
#define endl '\n'
#define NOCOM std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)
#define rge(i, x, y) for (int i = x; i <= y; i ++ )
// #define int long long
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
constexpr int N = 2e3 + 10, M = N * 2;
int h[N], e[M], ne[M], idx, cnt[N], d[N], pre[N];
int n, m;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
bool check(int a, int b) {
    queue<int> q;
    q.push(a);
    for (int i = 1; i <= n; i ++ ) d[i] = 10000;
    d[a] = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~ i; i = ne[i]) {
            int j = e[i];
            if (j == b && t == a) continue;
            if (d[j] > d[t] + 1) {
                d[j] = d[t] + 1;
                pre[j] = t;
                q.push(j);
            }
        }
    }
    if (d[b] < 10000) {
        vector<int> inv;
        vector<PII> g {{a, b}};
        unordered_set<int> st {a};
        while (b != a) {
            g.push_back({b, pre[b]});
            inv.push_back(b);
            st.insert(b);
            b = pre[b];
        }
        for (int i : inv) {
            if (cnt[i] > 3) {
                cout << "YES" << endl;
                int s = 0;
                for (int j = h[i]; ~ j; j = ne[j]) {
                    if (s == 2) break;
                    if (st.find(e[j]) == st.end()) {
                        g.push_back({i, e[j]});
                        s ++ ;
                    }
                }
                cout << g.size() << endl;
                for (PII a : g) 
                    cout << a.x << ' ' << a.y << endl;
                return true;
            }
        }
    }
    return false;
}
void solve() {
    memset(h, -1, sizeof h), memset(cnt, 0, sizeof cnt), idx = 0;
    cin >> n >> m;
    rge(i, 1, m) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
        cnt[a] ++ , cnt[b] ++ ;
    }
    rge(i, 1, n) {
        int a = i;
        for (int j = h[a]; ~ j; j = ne[j]) {
            int b = e[j];
            if (check(a, b)) return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    NOCOM;
    int t;
    cin >> t;
    rge(i, 1, t) solve();
    
    return 0;
}
