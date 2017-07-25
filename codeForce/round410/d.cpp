/*************************************************************************
> File Name: d.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Sun 23 Apr 2017 07:06:05 PM CST
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAX 100005

struct node {
    int a, b, id;
    friend bool operator < (node x, node y) {
        return x.a>y.a;
    }
} s[MAX];
int n;

void solve() {
    sort(s+1, s+1+n);
    printf("%d",s[1].id);
    for (int i = 2; i+1 <= n; i+=2) {
        if (s[i].b > s[i+1].b) {
            printf(" %d", s[i].id);
        } else {
            printf(" %d", s[i+1].id);
        }
    }
    if(n % 2 == 0) {
        printf(" %d\n", s[n].id);
    } else {
        printf("\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i].a);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i].b);
            s[i].id = i;
        }
        printf("%d\n",n/2+1);    
        solve();
    }

    return 0;
}
