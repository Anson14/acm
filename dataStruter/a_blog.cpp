#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100010;
struct edge {
    int to, next;
} g[N * 2];
int n, m, tot;
int cnt, head[N];
int len, root[N], lson[N * 20], rson[N * 20], val[N * 20];
int num, dep[N * 2], ver[N * 2], fir[N], dp[20][N * 2], fat[N];
bool vis[N];
int a[N], b[N];

void add_edge(int v, int u) {
    g[cnt].to = u, g[cnt].next = head[v], head[v] = cnt++;
}
void build(int l, int r, int &rt) {
    rt = ++tot;
    val[rt] = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, lson[rt]);
    build(mid + 1, r, rson[rt]);
}
void update(int pre, int &rt, int l, int r, int v) {
    rt = ++tot;
    lson[rt] = lson[pre], rson[rt] = rson[pre], val[rt] = val[pre] + 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(v <= mid) update(lson[pre], lson[rt], l, mid, v);
    else update(rson[pre], rson[rt], mid + 1, r, v);
}
void dfs(int v, int fa, int d) {
    vis[v] = true, ver[++num] = v, dep[num] = d, fir[v] = num, fat[v] = fa;
    update(root[fa], root[v], 1, len, a[v]);//在父节点的基础上新建一棵树
    for(int i = head[v]; i != -1; i = g[i].next) {
        int u = g[i].to;
        if(! vis[u]) {
            dfs(u, v, d + 1);
            ver[++num] = v, dep[num] = d;
        }
    }
}
void ST(int n) {
    for(int i = 1; i <= n; i++) dp[0][i] = i;
    for(int i = 1; (1 << i) <= n; i++)
        for(int j = 1; j <= n - (1 << i) + 1; j++)
            dp[i][j] = dep[dp[i - 1][j]] < dep[dp[i - 1][j + (1 << (i - 1))]] ? dp[i - 1][j] : dp[i - 1][j + (1 << (i - 1))];
}
int RMQ(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return dep[dp[k][l]] < dep[dp[k][r - (1 << k) + 1]] ? dp[k][l] : dp[k][r - (1 << k) + 1];
}
int LCA(int v, int u) {
    v = fir[v], u = fir[u];
    if(v > u) swap(v, u);
    int res = RMQ(v, u);
    return ver[res];
}
int query(int ss, int tt, int lca, int lca_fa, int l, int r, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int tmp = val[lson[ss]] + val[lson[tt]] - val[lson[lca]] - val[lson[lca_fa]];
    if(k <= tmp) return query(lson[ss], lson[tt], lson[lca], lson[lca_fa], l, mid, k);
    else return query(rson[ss], rson[tt], rson[lca], rson[lca_fa], mid + 1, r, k - tmp);
}
int main() {
    freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF) {
        //scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
        sort(b + 1, b + 1 + n);
        len = unique(b + 1, b + 1 + n) - b - 1;
        for(int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
        cnt = 0;
        memset(head, -1, sizeof head);
        for(int i = 1; i <= n - 1; i++) {
            int v, u;
            scanf("%d%d", &v, &u);
            add_edge(v, u), add_edge(u, v);
        }
        tot = 0;
        build(1, len, root[0]);
        num = 0;
        memset(vis, 0, sizeof vis);
        dfs(1, 0, 1);
        ST(2 * n - 1);
        for(int i = 1; i <= m; i++) {
            int v, u, k;
            scanf("%d%d%d", &v, &u, &k);
            int lca = LCA(v, u);
            printf("%d\n", b[query(root[v], root[u], root[lca], root[fat[lca]], 1, len, k)]);
        }
    }
    return 0;
}
