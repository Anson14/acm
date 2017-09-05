/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Sat Aug 19 2017 13:26:35
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

int t, a, b;
int n, s[3005][3005];

int main() {
    freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j <= n; j++) {
				scanf("%d", &s[i][j]);
				s[j][i] = s[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d ", s[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
    return 0;
}

