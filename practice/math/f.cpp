/*************************************************************************
> File Name: f.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Tue 02 May 2017 04:17:52 PM CST
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <utility>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 10005
#define pii pair<int, int>
#define mp make_pair

int prim[MAXN];
int k, m, n;
bool vis[MAXN];

void getPrim() {
    memset(prim, 1, sizeof(prim));
    prim[0] = prim[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        if(prim[i]) {
            for (int j = 2*i; j < MAXN; j += i) {
                prim[j] = 0;
            }
        }
    }
}

void bfs() {
    queue<pii> q;
    q.push(mp(m,0));
    clr(vis);
    vis[m] = true;
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        if (t.first == n) {
            printf("%d\n", t.second);
            return;
        }
        int p = t.first % 1000;
        for (int i = 1000; i < 10000; i += 1000) {
            if (prim[p+i] && !vis[p+i]) {
                q.push(mp(p+i, t.second+1));
                vis[p+i] = true;
            }
        }
        p = t.first % 100 + t.first/1000*1000;
        for (int i = 0; i < 1000; i += 100) {
            if (prim[p+i] && !vis[p+i]) {
                q.push(mp(p+i, t.second+1));
                vis[p+i] = true;
            }
        }
        p = t.first % 10 + t.first/100*100;
        for (int i = 0; i < 100; i+=10) {
            if (prim[p+i] && !vis[p+i]) {
                q.push(mp(p+i, t.second + 1));
                vis[p+i] = true;
            }
        }
        p = t.first/10*10;
        for (int i = 0; i < 10; i++) {
            if(prim[p+i] && !vis[p+i]) {
                q.push(mp(p+i, t.second+1));
                vis[p+i] = true;
            }
        }
    }
    printf("Impossible\n");
}

int main() {
    ios::sync_with_stdio(false);
    getPrim();
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &m, &n);
        bfs();
    }

    return 0;
}
