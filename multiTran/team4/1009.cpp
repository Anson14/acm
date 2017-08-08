/*************************************************************************
> File Name: 1009.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年08月03日 星期四 20时25分04秒
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

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    int t, n,a;
    scanf("%d", &t);
    while (t--) {
        int ans = 0, ans1 = 0;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &a);
            if (a&1)
                ans++;
            else 
                ans1++;
        }
        if (ans > ans1) {
            printf("2 %d\n", 1);
        } else {
            printf("2 %d\n", 0);
        }
    }

    return 0;
}
