/*************************************************************************
	> File Name: hd1003_On.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 11 May 2017 03:37:56 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int n, a[MAXN];
int d[MAXN];

int main() {
	ios::sync_with_stdio(false);
    while(scanf("%d", &n) != EOF) {
        for (int cnt = 1; cnt <= n; cnt++) {
            int m;
            scanf("%d", &m);
            for (int i = 1; i <= m; i++) {
                scanf("%d", &a[i]);
            }
            d[0] = 0;
            for (int i = 1; i <= m; i++) {
                d[i] = d[i-1] + a[i];
            }
            int minm = 99999999;
            for (int i = 1; i <= m; i++) {
                if (d[i] < minm) {
                    minm = d[i];
                }
            }
            int maxm = 0;
            for (int i = 1; i <= m; i++) {
                if (d[i] - minm > maxm) {
                    maxm = d[i]-minm;
                }
            }
            printf("%d\n", maxm);
        }
    }

	return 0;
}
