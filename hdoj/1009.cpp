/*************************************************************************
    > File Name: 1009.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: Thu 25 May 2017 09:22:27 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 1005

int n;
double m;
struct Food {
    double j, f;
    bool operator < (const Food &other) const {
        return j / f > other.j / other.f;
    }
} food[MAXN];

int main() {
    ios::sync_with_stdio(false);
    while (~scanf("%lf %d", &m, &n) && (m != -1 || n != -1)) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &food[i].j, &food[i].f);
        }
        sort(food, food + n);
        for (int i = 0; i < n; i++) {
        }
        int cnt = 0;
        double ans = 0.0;
        while (m != 0.0 && cnt < n) {
            if (m >= food[cnt].f) {
                m -= food[cnt].f;
                ans += food[cnt++].j;
            } else {
                ans += food[cnt].j / food[cnt].f * m;
                m = 0;
                cnt++;
            }
        }
        printf("%.3lf\n", ans);
    }

    return 0;
}
