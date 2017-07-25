/*************************************************************************
> File Name: 2015.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Wed 24 May 2017 09:10:11 PM CST
************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    while (~scanf("%d %d", &n, &m)) {
        int ans = 0, temp = 2, cnt = 0;
        bool flag = true;
        for (int i = 0; i < n; i ++) {
            ans += temp;
            cnt++;
            if (cnt == m) {
                ans /= m;
                if (flag) {
                    printf("%d", ans);
                    flag = false;
                }
                else
                    printf(" %d", ans);
                ans = 0;
                cnt = 0;
            }
            temp += 2;
        }
        if (cnt) {
            ans /= cnt;
            printf(" %d", ans);
        }
        printf("\n");
    }

    return 0;
}
