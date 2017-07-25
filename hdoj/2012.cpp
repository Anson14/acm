/*************************************************************************
> File Name: 2012.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Wed 24 May 2017 08:27:29 PM CST
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
#define MAXN 100

int a[100];
int prim[5000];

void getPrim() {
    memset(prim, 1, sizeof(prim));
    prim[0] = prim[1] = 0;
    for (int i = 2; i < 5000; i++) {
        if (prim[i]) {
            for (int j = 2*i; j < 5000; j += i) {
                prim[j] = 0;
            }

        }
    }
}

void fun() {
    int cnt = 0;
    for (int i = -39; i <= 50; i++) {
        a[cnt++] = i*i + i + 41;
        //printf("%d  %d   ", cnt , a[cnt-1]);
    }
}

int solve(int m, int n) {
    //printf("%d", a[39]);
    for (int i = 39+m; i <= 39+n;i++) {
        if(!prim[a[i]]) {
            printf("Sorry\n"); 
            return 0;
        }       
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    int m, n;
    fun();
    getPrim();
    while(~scanf("%d %d", &m, &n) && (m !=0 || n != 0) ) {
        if(solve(m, n))
            printf("OK\n");
    }

    return 0;
}
