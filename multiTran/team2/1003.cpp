/*************************************************************************
> File Name: 1003.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月27日 星期四 16时36分21秒
************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
//#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 250010

int n;
int q = 1e9+7;
int a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(false);
    freopen("in_c.txt", "r", stdin);
    while(~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", b+i);
        }

        int l = n;
        int p = n;
        int val = 0;
        for (int i = 0; i < n; i++) {
            int temp = 0, cho = 0;
            for (int j = 0; j < l; j++) {
                for (int x = b[j]; x < l; x++) {
                    if (a[x]-x-1 > temp)  {
                        temp = a[x]-x-1;
                        cho = x;
                    }
                }
                //printf("TEMP: %d", temp);
            }
            //printf("temp :%d", temp);
            swap(a[cho], a[l-1]);
            l--;
            p++;
            val += temp % q;
            if (val > q) {
                val %= q;
            }
            for (int i = 0; i < l; i++) {
                printf("  %d", b[i]);
            }
            printf("\n");
        }
        printf("%d", val);
    }

    return 0;
}
