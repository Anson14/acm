#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int camp[50001];
struct Tree {
    int l, r, sum;
}tree[200000];
void build(int num,int l,int r) {
    tree[num].l = l;
    tree[num].r = r;
    if (tree[num].l == tree[num].r) {
        tree[num].sum = camp[l];
        return;
    }
    int mid = (l + r) / 2;
    build(num << 1, l, mid);
    build(num << 1 | 1, mid + 1, r);
    tree[num].sum = tree[num << 1].sum + tree[num << 1 | 1].sum;
}
void update(int num,int position,int value) {
    if (tree[num].l == tree[num].r) {
        tree[num].sum = value;
        return;
    }
    int mid = (tree[num].l + tree[num].r) / 2;
    if (position <= mid)
        update(num << 1, position, value);
    else
        update(num << 1 | 1, position, value);
    tree[num].sum = tree[num << 1].sum + tree[num << 1 | 1].sum;
}
int query(int num,int left,int right) {
    if (left <= tree[num].l && right >= tree[num].r)
        return tree[num].sum;
    int mid = (tree[num].l + tree[num].r) / 2, t = 0;
    if (left <= mid) t += query(num << 1, left, right);
    if (right > mid) t += query(num << 1 | 1, left, right);
    return t;
}
int main() {
    freopen("in.txt", "r", stdin);
    int T, cas = 1, n,  a, b, i;
    char str[10];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", &camp[i]);
        build(1, 1, n);
        printf("Case %d:\n", cas++);
        while (scanf("%s", str) && strcmp(str, "End")) {
            scanf("%d%d", &a, &b);
            if (strcmp(str, "Query") == 0) {
                if (a > b) swap(a, b);
                printf("%d\n", query(1, a, b));
            }
            else if (strcmp(str, "Add") == 0) {
                camp[a] += b;
                update(1, a, camp[a]);
            }
            else if (strcmp(str, "Sub") == 0) {
                camp[a] -= b;
                update(1, a, camp[a]);
            }
        }
    }
    return 0;
}
