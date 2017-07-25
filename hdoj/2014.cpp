/*************************************************************************
> File Name: 2014.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Wed 24 May 2017 08:53:34 PM CST
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

int main() {
    ios::sync_with_stdio(false);
    int n = 0;
    while(~scanf("%d", &n)) {
        double ans = 0, cc = 0, mi = 1000, ma = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &cc);
            ans += cc;
            if (mi > cc) 
            mi = cc;
            if (ma < cc)
            ma = cc;
        }
        ans -= ma+mi;
        printf("%.2f\n", ans/(n-2));
    }

    return 0;
}
