/*************************************************************************
	> File Name: c.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Fri 12 May 2017 03:28:59 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int n;
LL k;
LL a[MAXN];

bool judge (LL t) {
    LL u = t;
    LL th = 0;
    for (int i = 1; i <= n; i++) {
        th = a[i] - t;
        if (th >0) {
            u -= (th+k-2)/(k-1);     //此处不懂！！！
        }
    }
    if (u < 0) {
        return false;
    }
    return true;
}

int main() {
	ios::sync_with_stdio(false);
    while(~scanf("%d", &n)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%I64d", &a[i]);
        }
        scanf("%I64d", &k);
        sort(a+1, a+1+n);
        LL l = a[1];
        LL r = a[n];
        while (l < r) {
            LL mid = l+(r-l)/2;
            if (judge(mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        if (k == 1) {
            l = a[n];
        }
        printf("%I64d\n", l);
    }

	return 0;
}
