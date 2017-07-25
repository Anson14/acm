/*************************************************************************
	> File Name: 2011.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 24 May 2017 08:09:38 PM CST
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
#define MAXN 1005

double fun(double x) {
    double ans = 1;
    
    for (int i = 2; i <= x; i++) {
        if (i&1) {
            ans += 1.0/i; 
        } else {
            ans -= 1.0/i;
        }
    }
    return ans;
}
int main() {
	ios::sync_with_stdio(false);
    int m;
    scanf("%d", &m);
    while (m--) {
        double n = 0;
        scanf("%lf", &n);
        printf("%.2lf\n", fun(n));
    }

	return 0;
}
