/*************************************************************************
    > File Name: 1006.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月08日 星期二 13时40分44秒
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

int t, n;
LL m, ans, temp;

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld", &n, &m);
        if (n == 1) {
            printf("0\n");
        } else if (n == 2) {
            if (m >= 1)
                printf("1\n");
            else
                printf("2\n");
        } else if (n == 3) {
            if (m == 0)
                printf("18\n");
            if (m == 1)
                printf("14\n");
            else
                printf("6\n");
        } else {
            temp = n * (n - 3) / 2 + n;
            if (m >= temp) {
                ans = n * (n - 1);
            } else if (m >= n) {
                temp = (n / 2) * (n / 2);
                if (n % 2 == 1) {
                    temp += (n / 2);
                }
                temp *= n;
                ans = temp - 2 * (m - n);
            } else {
                ans = (n - 1) * n * (n - 1 - m) + ((n - 1 - m) * n + m) * (m + 1);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
