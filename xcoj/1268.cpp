/*************************************************************************
> File Name: 1268.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月11日 星期二 11时33分52秒
************************************************************************/

#include <iostream>
#include <queue>
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

struct node {
    int x, y, step;
}u, v;
queue<node> que;
char s[200];
int map[200][200];
int stepm[200][200];
int dirx[4] = {0,0,-1,1}, diry[4] = {1,-1,0,0};
int n,m,t,k,sx,sy,tx,ty;

void init() {
    clr(map);
    
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 0; j < (int)strlen(s); j++) {
            if (s[j] == 'S') {
                sx = i;
                sy = j+1;
                map[i][j+1] = 1;
            }
            if (s[j] == 'T') {
                tx = i;
                ty = j+1;
                map[i][j+1] = 1;
            }
            if (s[j] == '.') {
                map[i][j+1] = 1;
            }
        }
    }

    while(!que.empty()) {
        que.pop();
    }
    return ;
}

void bfs() {
    while (!que.empty()) {
        u = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            v = u;
            v.x += dirx[i];
            v.y += diry[i];
            v.step++;
            if (map[v.x][v.y]) {
                //表示这条路走过了
                map[v.x][v.y] = 0;
                stepm[v.x][v.y] = v.step;
                que.push(v);
            }
        }
    }
    return;
}

int main() {
    freopen("1.in", "r", stdin);
    while (~scanf("%d %d",&n, &m)) {
        init();
        u.x = sx;
        u.y = sy;
        u.step = 1;
        que.push(u);
        bfs();
        if (map[tx][ty]) {
            printf("Impossible\n");
        } else {
            printf("%d\n", stepm[tx][ty]);
        }
    }

    return 0;
}
