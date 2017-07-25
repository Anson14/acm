/*************************************************************************
    > File Name: 2019.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: Thu 25 May 2017 08:49:46 PM CST
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
#define MAXN 1000

int m, n;

int main() {
    ios::sync_with_stdio(false);
    while (~scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        int a = 0;
        bool flag = true;
        scanf("%d", &a);
        if (n < a) {
            printf("%d ", n);
            flag = false;
        }
        printf("%d", a);
        for (int i = 1; i < m; i++) {
            scanf("%d", &a);
            if (n < a && flag) {
                printf(" %d %d", n, a);
                flag = false;
            } else printf(" %d", a);
        }
        if (flag) printf(" %d", n);
        printf("\n");
    }

    return 0;
}
