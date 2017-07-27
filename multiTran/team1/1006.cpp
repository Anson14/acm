/*************************************************************************
    > File Name: 1006.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年07月26日 星期三 10时15分40秒
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
#define MAXN 100020

int m, n;
int a[MAXN], b[MAXN];
int f[MAXN];
int loopa[MAXN], loopb[MAXN];
int ca = 1;

int main() {
    ios::sync_with_stdio(false);
    while (~scanf("%d %d", &n, &m)) {
        clr(a); 
        clr(b);
        clr(loopa);
        clr(loopb);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        int visit[MAXN];
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                int x = a[i];
                int cnt = 0;
                while(!visit[x]) {
                    visit[x] = 1;
                    cnt++;
                    x = a[x];
                }
                loopa[cnt]++;
            }
        }
        clr(visit);
        for (int i = 0; i < m; i++) {
            if (!visit[i]) {
                int x = b[i];
                int cnt = 0;
                while(!visit[x]) {
                    visit[x] = 1;
                    cnt++;
                    x = b[x];
                }
                loopb[cnt]++;
            }
        }
        LL val = 0;
        for (int i = 0; i < n; i++) {
            LL temp = 0;
            for (int j = 0; j < i; j++) {
                temp += 
            }
        }
    }

    return 0;
}
