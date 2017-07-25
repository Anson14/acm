/*************************************************************************
> File Name: c.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Sun 23 Apr 2017 11:33:43 AM CST
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAX 100005

int n, ans;
int a[MAX];

int gcd(int a, int b) {
    return b ? gcd(b, a%b):a;
}


int main() {
    ios::sync_with_stdio(false);
    while ((scanf("%d", &n) != EOF)){
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);        
        }
        printf("Yes\n");
        int g = gcd(a[0], a[1]);
        for (int i = 2; i < n; i++) {
            g = gcd(g, a[i]);
        }
        if (g != 1) {
            printf("0\n");
            continue;
        } else {
            bool flag = false;
            ans = 0;
            if ((a[0] & 1) == 0) {
                flag = false;
            } else {
                flag = true;
            }
            for (int j = 1; j < n; j++) {
                if ((a[j] & 1) == 1) {
                    if (flag) {
                        ans ++;
                        flag = false;
                    } else {
                        flag = true;
                    }
                } else {
                    if (flag) {
                        ans += 2;
                        flag = false;
                    } else {
                        flag = false;
                    }   
                }
            }
            if (flag) {
                ans += 2;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
