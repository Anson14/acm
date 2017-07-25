/*************************************************************************
	> File Name: 2016.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 24 May 2017 09:28:42 PM CST
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
#define MAXN 105

int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (~scanf("%d", &n) && n) {
        int mi = 999999999, temp = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] < mi) {
                mi = a[i];
                temp = i;
            }
        }
        swap(a[0], a[temp]);
        printf("%d", a[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
