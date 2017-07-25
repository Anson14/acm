/*************************************************************************
	> File Name: e.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Mon 01 May 2017 07:49:53 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 10000005

int m;
int prim[MAXN];

void getPrim() {
    memset(prim, 1, sizeof(prim));
    prim[0] = prim[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (prim[i]) {
            for (int j = 2*i; j < MAXN; j+=i) {
                prim[j] = 0;
            }
        }
    }
}

void solve(int n) {
    int hah = 0;
    if(prim[n]) {
        printf("0\n");
        return;
    }
    for (int i = n; i <= MAXN; i++) {
        if(prim[i]) {
            hah = 1;
            for (int j = i-1; j >= 0; j--) {
                if (prim[j]) {
                    break;
                }
                //printf("%d ", hah);
                hah++;
            }
            break;
        }
    }
    printf("%d\n", hah);
}

bool ok(int n) {
    for (int i = n-1; i >= 2; i--) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve_b(int n) {
    int ans = 0;
    if(ok(n)) {
        printf("0\n");
        return;
    }
    for (int i = n; i < MAXN; i++)  {
        if (!ok(i)) {
            ans++;
        }
        if(ok(i)) {
            break;
        }
    }
    for (int j = n-1; j >= 2; j--) {
        if (!ok(j)) {
            ans++;
        }
        if(ok(j)) {
            break;
        }
    }
    printf("%d\n", ans+1);
}

int main() {
    ios::sync_with_stdio(false);
    //getPrim();
    while (scanf("%d", &m) != EOF && m) {
        //solve(m);
        solve_b(m);
    }

    return 0;
}
