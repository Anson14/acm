/*************************************************************************
> File Name: main.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月26日 星期三 20时38分20秒
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
#define MAXN 1005

char str[105];
int dp[105][105];

bool check(char a, char b) {
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin"");
    while (~scanf("%s", str)) {
        if (str[0] == 'e') {
            break;
        }
        clr(dp);
        int len = (int)strlen(str);
        for (int l = 1; l < len; l++) {    //此处选择区间长度，从1到k;
            for (int i = 0, j = l; j < len; i++, j++) {
                if (check(str[i], str[j])) {
                    dp[i][j] = dp[i+1][j-1]+2;    //(i, j)的子区间的配对数的基础上在加上2
                }
                for (int x = i; x < j; x++ ) {
                    //dp[i][j] = max(dp[i][j], dp[i][x]+dp[x][j]);
                }        
            }
        }

        printf("%d\n", dp[0][len-1]);
    }

    return 0;
}
