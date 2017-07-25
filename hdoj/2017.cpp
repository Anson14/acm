/*************************************************************************
> File Name: 2017.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Wed 24 May 2017 09:36:13 PM CST
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

char s[MAXN];

struct hh {
    int nihao;
    char hhhhhh;
} nnnn;

int main() {
    ios::sync_with_stdio(false);    

    int n = 0;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", s);
        int ans = 0;
        for (int i = 0; i < (int)strlen(s); i++) {
            if (s[i] >= '0' && s[i] < '9') {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
