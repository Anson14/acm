/*************************************************************************
    > File Name: a.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年06月25日 星期日 14时04分55秒
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
#define MAXN 1005

int n = 0;

struct Tr {
    int val, pre, deep;
    bool now = false;
} tree[10005];

bool judge() {
    for (int i = 1; i <= n; i++) {
        if (!tree[i].now) {
            return false;
        }
    }
    return true;
}

void search(int t) {
    int x = tree[t].val;
    int z = t;
    while (x--) {
        tree[z].now = true;
        z = tree[z].pre;
    }
}
int find () {
    int maxm = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!tree[i].now && tree[i].deep > maxm) {
            maxm = tree[i].deep;
            ans = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (tree[i].pre == ans) {
            if (tree[i].val > tree[i].deep && tree[i].val - 1 > tree[ans].val) {
                ans = i;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n)) {
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &tree[i].pre);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &tree[i].val);
        }
        tree[1].deep = 1;
        for (int i = 2; i <= n; i++) {
            tree[i].deep = tree[tree[i].pre].deep + 1;
        }

        for (int i = 1; i <= n; i++) {
            tree[i].now = false;
            //printf("%d  %d   %d   %d   \n", i, tree[i].deep, tree[i].val, tree[i].now);
        }
        while (!judge()) {
            int i = find();
            search(i);
            //for (int i = 1; i <= n; i++) {
            //printf("%d  ", tree[i].now);
            //}
            cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
