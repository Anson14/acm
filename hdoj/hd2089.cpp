/*************************************************************************
	> File Name: hd2089.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 18 May 2017 02:09:23 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int a[20], dp[20][2];

//此为数位dp模板，比较重要！需要自习研究，对于不同的题目，这个函数需要按需修改
int dfs(int pos, int pre, int sta, bool limit) {
    if (pos == -1)
        return 1;
    if (!limit && dp[pos][sta] != -1)
        return dp[pos][sta];
    int up = limit ? a[pos] : 9;
    int tmp = 0;
    for (int i = 0; i <= up; i++) {
        if(pre == 6 && i == 2) {
            continue;
        }
        if (i == 4 )
            continue;
        tmp += dfs(pos - 1, i, i == 6, limit && a[pos]);
    }
    if (!limit)
        dp[pos][sta] = tmp;
    return tmp;
}

int getIt(int a, int b) {
    for (int i = 0; i < a; i++) {
        if (i < a && i > b) {
            return i;
        }
    }
}

int solve(int x) {
    int pos = 0;
    while (x) {
        a[pos] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, -1, 0, true);
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        printf("%d\n", solve(m) - solve(n - 1));
    }

    return 0;
}
