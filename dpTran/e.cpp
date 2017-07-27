/*************************************************************************
    > File Name: e.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年07月27日 星期四 09时57分03秒
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
#define MAXN 105

int n;
int a[MAXN];
int dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
        }
        clr(dp);
        for (int l = 2; l <= n; l++) {
            for (int i = 0, j = l; j < n; i++, j++) {
                dp[i][j] = 1e9;
                for(int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][k]+dp[k][j]+a[i]*a[j]*a[k], dp[i][j]);
                }
            }
        }
        printf("%d\n", dp[0][n-1]);
    }

    return 0;
}
