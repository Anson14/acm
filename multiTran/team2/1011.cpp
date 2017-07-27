/*************************************************************************
> File Name: 1011.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月27日 星期四 13时24分14秒
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
#define MAXN 510

int n;
int p[MAXN][2];
int ma[500][500];


int main() {
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n)){
        clr(ma);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i][0], &p[i][1]);
            p[i][0] += 100;
            p[i][1] += 100;
            ma[p[i][0]][p[i][1]] = 1;
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (p[i][0] == p[j][0]) {
                    int len = abs(p[i][1]-p[j][1]);
                    if (ma[p[i][0]+len][p[i][1]] && ma[p[j][0]+len][p[j][1]]) {
                        cnt++;
                        if (len % 2 == 0) {
                            if (ma[p[i][0]+len/2][p[i][1]] && ma[p[i][0]][p[i][1]+len/2] && ma[p[j][0]+len/2][p[j][1]] && ma[p[i][0]+len][p[i][1]+len/2]) {
                                cnt++;
                            }
                        }
                    }
                }
                else if (p[i][1] == p[j][1]) {
                    int len = abs(p[i][0] - p[j][0]);
                    if (ma[p[i][0]][p[i][1]+len] && ma[p[j][0]][p[j][1]+len]) {
                        cnt++;
                        if (len % 2 == 0) {
                            if (ma[p[i][0]+len/2][p[i][1]] && ma[p[i][0]][p[i][1]+len/2] && ma[p[j][0]][p[j][1]+len/2] && ma[p[i][0]+len/2][p[i][1]+len]) {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt/2);
    }

    return 0;
}
