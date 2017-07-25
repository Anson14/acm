/*************************************************************************
	> File Name: c.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Sun 30 Apr 2017 11:18:24 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAX 101000

int prim[MAX];
int vist[MAX];
int ans[MAX];
int m, n, d;

void getPrime() {
    memset(prim, 1, sizeof(prim));
    prim[0] = prim[1] = 0;
    for (int i = 2; i < MAX; i++) {
        if (prim[i]) {
            for (int j = 2*i; j < MAX; j+= i) {
                prim[j] = 0;//把素数的倍数都是非素数
            }
       }
    }
}

bool ok(int a, int num) {
    if (a == 0) {
        return true;
    }
    int left = a-d+1;
    if (left < 0) {
        left = 0;
    }
    int sum = num;
    for (int i = a-1; i >= left; i--) {
        sum += ans[i];
        if (prim[sum]) {
            return false;
        }
    }
    return true;
}

bool dfs(int a) {
    if(a == n-m+1) {
        return true;
    }
    for (int i = m; i <= n; i++) {
        if (!vist[i] && ok(a, i)) {
            ans[a] = i;
            vist[i] = 1;
            if (dfs(a+1)) {
                return true; 
            }
            vist[i] = false;  //这个是如果发现i不可以的话就回溯（ans不用动因为回溯的时候会需要改变ans数组）
        }
    }
    return false;
}

int main() {
	ios::sync_with_stdio(false);
    getPrime();
    while (scanf("%d %d %d", &m, &n, &d)) {
        if (m == 0 && n == 0 && d == 0) {
            return 0;
        }
        clr(ans);
        clr(vist);
        if(!dfs(0)) {
            printf("No anti-prime sequence exists.");
        }else {
            printf("%d", ans[0]);
            for (int i = 1; i < n-m+1; i++) {
                printf(",%d" , ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
