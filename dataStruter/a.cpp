/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Tue Sep 05 2017 8:18:48
************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

struct Node {
    LL weigth;
    int father;
    int deep = 0;
} nodes[MAXN];
int n, m;
struct Edge {
    int mi, ma;
    bool operator <(const Edge other) {
        return mi < other.mi;
    }
} edge[MAXN];

void solve() {
    for (int q = 0; q < m; q++) {
        int u, v, k;
        LL num[MAXN];
        cin >> u >> v >> k;

        int find = 0;
        int p = 0;
        if (nodes[u].deep <  nodes[v].deep)
            swap(u, v);
        while (nodes[u].deep > nodes[v].deep) {
            num[p++] = nodes[u].weigth;
            u = nodes[u].father;
        }
        if (u == v) {

        } else
            while (!find) {
                num[p++] = nodes[v].weigth;
                num[p++] = nodes[u].weigth;
                v = nodes[v].father;
                u = nodes[u].father;
                if (u == v)
                    find = 1;
            }
        num[p++] = nodes[u].weigth;
        sort(num, num + p);
        cout << num[k - 1] << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> nodes[i].weigth;
        }
        nodes[1].deep = 1;
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            //nodes[a].child.push_back(b);
            edge[i].mi = a;
            edge[i].ma = b;
        }
        sort(edge + 1, edge + n);
        bool flag = false;
        int temp = 0;
        for (int i = 1; i < n; i++) {
            if (edge[i].ma == 0) {
                continue;
            }
            if (nodes[edge[i].mi].deep == 0) {
                flag = true;
                temp = i;
                continue;
            }
            nodes[edge[i].ma].father = edge[i].mi;
            nodes[edge[i].ma].deep = nodes[edge[i].mi].deep + 1;
            if (flag) {
                flag = false;
                edge[i].ma = 0;
                i = temp - 1;
            }
        }
        solve();
    }


    return 0;
}
