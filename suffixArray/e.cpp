/*************************************************************************
    > File Name: e.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年07月29日 星期六 21时10分24秒
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
#define clr1(x) memset(x, -1, sizeof(x))
using namespace std;
#define MAXN 1000010

int F[MAXN];

void getF(char *str) {
    clr1(F);
    int m = strlen(str);
    for (int i = 1; i < m; i++) {
        int j = F[i-1];
        while (str[j+1] != str[i] && (j>=0)) {
            j = F[j];
        }
        if (str[j+1] == str[i]) {
            F[i] = j+1;
        } else {
            F[i] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    char a[MAXN];
    while (~scanf("%s", a)) {
        if (a[0] == '.') {
            break;
        }
        getF(a);
        int len = strlen(a);
        int ans = 1;
        if (len % (len - F[len-1]-1) == 0) {
            ans = len/(len-F[len-1]-1);
        }
        printf("%s", a);
        for (int i = 0; i < len; i++) {
            printf("%d ",F[i]);
        }
        printf("%d\n", ans);
        printf("%d\n", ans);
    }

    return 0;
}
