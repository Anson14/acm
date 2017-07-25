/*************************************************************************
> File Name: 2010.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Wed 24 May 2017 07:40:12 PM CST
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
#define MAXN 1000

int m, n;
int a[MAXN];

bool judge(int x) {
    int a = x %10;
    int b = (x/10)%10;
    int c = x/100;
    if (a*a*a + b*b*b + c*c*c == x) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int cnt = 0;
    for (int i = 100; i <= 999; i++) {
        if (judge(i))
        a[cnt++] = i;
    }
    while (~scanf("%d %d", &n, &m)) {
        bool flag = true;
        if (m < n) {
            swap(m, n);
        }
        for (int i = 0; i < 100; i++) {
            if (a[i] >=n) {
                if (a[i] > m) {
                    break;
                } else {
                    if (flag)
                        printf("%d", a[i]);
                    else 
                        printf(" %d", a[i]);
                    flag = false;
                }
            }
        }
        if (flag) 
            printf("no\n");
        else 
            printf("\n");
    }
    return 0;
}
