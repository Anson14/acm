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
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 1010

int n;
int p[MAXN][2];
int ma[1010][1010];


int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n)){
        clr(ma);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i][0], &p[i][1]);
            p[i][0] += 500;
            p[i][1] += 500;
            ma[p[i][0]][p[i][1]] = 1;
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int lenx, leny;
                if ((p[i][0]-p[j][0]) * (p[i][1]-p[j][1]) > 0) {
                    lenx = -abs(p[i][1]-p[j][1]);
                    leny = abs(p[i][0]-p[j][0]);
                }else {
                    lenx = abs(p[i][1]-p[j][1]);
                    leny = abs(p[i][0]-p[j][0]);
                }
                if (ma[p[i][0]+lenx][p[i][1]+leny] && ma[p[j][0]+lenx][p[j][1]+leny]) {
                    cnt++;
                    //printf("%d,%d  %d,%d\n", p[i][0]-100, p[i][1]-100, p[j][0]-100, p[j][1]-100);
                }
                if (ma[p[i][0]-lenx][p[i][1]-leny] && ma[p[j][0]-lenx][p[j][1]-leny]) {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt/4);
    }

    return 0;
}
