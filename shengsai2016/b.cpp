/*************************************************************************
	> File Name: b.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 17 May 2017 10:33:17 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int t, a[1005], b;

int main() {
	ios::sync_with_stdio(false);
    scanf("%d", &t);
    while (t--) {
        int k = 0;
        scanf("%d", &k);
        clr(a);
        for (int i = 0;i < k; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &b);
        sort(a, a+k);
        int z = 1, temp = a[k-1];
        for (int i = k-1; i >= 0; i--) {
            if (a[i] != temp) {
                z++;
                temp = a[i];
            }
            if (z == b) {
                printf("%d\n", a[i]);
                break;
            }
        }
    }

	return 0;
}
