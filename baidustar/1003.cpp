/*************************************************************************
    > File Name: 1003.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月05日 星期六 13时12分33秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
//#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 1005

int n, m;

struct evil {
    int life, defense;
    bool operator < (const evil &other) const {
        return defense < other.defense;
    }
} e[100005];

struct dudu {
    int consume, hurt;
    bool operator <(const dudu &other) const {
        if (hurt/consume == other.hurt/other.consume) {
            if (hurt % consume == other.hurt % other.consume) {
                return consume < other.consume;
            } else  {
                return hurt % consume > other.hurt % other.consume;
            }
        } else {
            return hurt/consume > other.hurt/other.consume;
        }
    }
} d[MAXN];

struct duJX {
    int consume, hurt;
    bool operator < (const duJX &other) const {
        return consume < other.consume;
    }
} dj[MAXN];

LL get(int i, int j) {
    LL a = 0;
    int k = e[i].life;
    while (k>0) {
        for (int x = 0; x < m; x++) {
            if (dj[x].hurt - e[i].defense >= k) {
                if (dj[x].consume < d[j].consume*(k/(d[j].hurt - e[i].defense)+1&(k%(d[j].hurt - e[i].defense)))) {
                    return a+dj[x].consume;
                }
            }
        }
        a += d[j].consume;
        k -= (d[j].hurt - e[i].defense);
    }
    return a;
}

void solve() {
    bool flag = false;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j == m) {
                flag = true;
                break;
            }
            if (d[j].hurt > e[i].defense) {
                ans += get(i, j);
                //printf("%d %d\n", d[j].consume, d[j].hurt);
                break;
            }
        }
    }
    if (flag) {
        printf ("-1\n");
    } else {
        printf("%I64d\n",ans);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &e[i].life, &e[i].defense);
        }
        for (int j = 0; j < m; j++) {
            scanf("%d %d", &d[j].consume, &d[j].hurt);
            dj[j].consume = d[j].consume, dj[j].hurt = d[j].hurt;
        }
        sort(e, e+n); sort(d, d+m); sort(dj, dj+m);
        solve();
    }

    return 0;
}
