/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Sat Aug 12 2017 15:0:16
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

int t;
char s[12];

bool isBig(int year) {
    if (year%4==0&&year%100!=0) {
        return true;
    }
    if (year%400==0) {
        return true;
    }
    return false;
}

struct a {
    int v;
} b;

int main() {
    // ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        int y,m,d;
        scanf("%d-%d-%d", &y,&m,&d);
        int temp = 0;
        int ans = 0;
        if (isBig(y)) {
            if (m == 2 && d == 29) {
                printf("%d\n", y+28);
                continue;
            }
            if (m>2) {
                printf("%d\n", y+1);
            } else {
                printf("%d\n", y+5);
            }
        } else if(isBig(y-1)) {
            printf("%d\n", y+6);
        } else if (isBig(y-2)) {
            printf("%d\n", y+6);
        } else if (isBig(y-3)) {
            printf("%d\n", y+11);
        }
    }

    return 0;
}
