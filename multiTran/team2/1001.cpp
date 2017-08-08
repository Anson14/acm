/*************************************************************************
> File Name: 1001.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月27日 星期四 12时35分43秒
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
#define MAXN 80005

int n, t;
char a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca++) {
        int x = 0, y = 0;
        scanf("%d %d %d", &n, &x, &y);
        scanf("%s", a);
        scanf("%s", b);
        if (x > n || y > n) {
            printf("Lying\n");
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                cnt++;
            }
        }
        if (x <= n) {
            if (y <= n-abs(cnt-x)) {
                if (n - x  < cnt) {
                    if (y < cnt-(n-x)) {
                        printf("Lying\n");
                        continue;
                    }
                }
                printf("Not lying\n");
                continue;
            }
            printf("Lying\n");
        }
    }
    

    return 0;
}
