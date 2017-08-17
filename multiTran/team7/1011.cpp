/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Tue Aug 15 2017 12:11:17
************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int t, n;
int a[10000005] = {1, 1, 2, 2};

void init() {
    int pre = 3;
    for (int i = 4; i < 10000005; i++) {
        if (a[pre] == 1) {
            if (a[i-1] == 1) {
                a[i] = 2;
            } else if (a[i-1] == 2) {
                a[i] = 1;
            }
            pre++;
        } else if (a[pre] == 2) {
            if (a[i-1] == 1) {
                // if (a[i-2] == 1) {
                    a[i] = 2;
                    a[++i] = 2;
                // } else {
                    // a[i] = 1;
                // }
            } else {
                // if (a[i-2] == 2) {
                    a[i] = 1;
                    a[++i] = 1;
                // } else {
                    // a[i] = 2;
                // }
            }
            pre++;
        }
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    init();
    // for (int i = 1; i <= 100; i++) {
        // printf("%d ", a[i]);
	// }
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
    return 0;
}
