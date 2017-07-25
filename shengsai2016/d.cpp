/*************************************************************************
	> File Name: d.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 17 May 2017 03:22:34 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 50000
int n,m,q,t, a[MAXN];

int main() {
	ios::sync_with_stdio(false);
    scanf("%d", &t);
    while (t--) {
        clr(a);
        scanf("%d%d%d", &n,&m,&q);
        for (int i = 0; i < n*m; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+m*n);
        while (q--) {
            int b = 0;
            scanf("%d", &b);
            int ans = 0;
            for (int j = n*m-1; j >= 0; j--) {
                if (a[j] <= b) {
                    break;
                }
                ans++;
            }
            printf("%d\n", ans);
        }
    }

	return 0;
}
