/*************************************************************************
    > File Name: 1004.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月01日 星期二 12时13分37秒
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
#define MAXN 500005

int t, n;
int num[MAXN];
int hah[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hah[i][j] = num[i]^num[j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", hah[i][j]);
            }
            printf("\n");
        }
        printf("%d\n", ans);
    }

    return 0;
}
