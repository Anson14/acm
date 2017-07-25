/*************************************************************************
> File Name: b.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Fri 28 Apr 2017 10:26:34 PM CST
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAX 32888

int num = 0;

void solve(int x) {
    int a[1000];
    int k = 0;
    clr(a);
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            a[k++] = i;
            while (x%i == 0) {
                a[k]++;
                x /= i;
            }
            k++;
        }
    }
    if (x > 1) {
        a[k++] = x;
        a[k++]++;
    }
    for (int i = k-1; i >= 1; i -= 2) {
        printf("%d %d%c", a[i-1],a[i], ((i == 1)? '\n':' '));
    }
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("b.txt", "r", stdin);
    while (1) {
        num = 1;
        while (1) {
            scanf("%d", &m);
            if (!m) {
                return 0;
            }
            scanf("%d", &n);
            num *= (int)pow((double)m,n);
            if (getchar() == '\n') {
                break;
            }
        }
        solve(num - 1);
    }

    return 0;
}
