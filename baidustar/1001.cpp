/*************************************************************************
    > File Name: 1001.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月05日 星期六 12时35分51秒
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
#define MAXN 20015

int p[MAXN][MAXN];
int m, n;

int main() {
    ios::sync_with_stdio(false);
	freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n)) {
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            p[a+1000][b+1000] = 1;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            p[a+1000][b+1000] = 2;
        }
        for (int i = 990; i <= 1020; i++) {
            for (int j = 990; j <= 1020; j++) {
                printf("%d ", p[i][j]);
            }
            printf("\n");
        }
            printf("\n");
            printf("\n");
    }

    return 0;
}
