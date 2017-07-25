/*************************************************************************
	> File Name: 2006.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 24 May 2017 11:13:13 AM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 1000

int a[MAXN];

int solve(int n) {
    int ans  = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            ans *= a[i];
        }
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
    int n = 0;
    while (~scanf("%d", &n)) {
        clr(a);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        int ans = solve(n);
        printf("%d\n", ans);
    }

	return 0;
}
