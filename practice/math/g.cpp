/*************************************************************************
> File Name: g.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Tue 02 May 2017 08:09:39 PM CST
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 2000

int prim[MAXN], m, n;

void getPrim() {
    prim[0] = 1;
    int vis[MAXN], tot = 1;
    for(int i=2;i<=MAXN;++i){
        if(vis[i]==0)
        prim[tot++]=i;
        for(int j=0;j<tot&&prim[j]*i<=MAXN;++j)
        vis[prim[j]*i]=1;
    }
}

void solve() {
    int hah = 0;
    for (int i = 0; i < MAXN; i++) {
        if (prim[i] > m) {
            hah  = i;
            break;
        }
    }
    if ((m&1) == 0) {
        if (2*n > hah) {
            for (int i = 0; i < hah; i++) {
                printf(" %d", prim[i]);
            }
        } else
        for (int i = (hah /2)-n; i < (hah /2)+n; i++) {
            printf(" %d",prim[i]);
        }
        printf("\n");
    } else {
        if (2*n-1 > hah) {
            for (int i = 0; i < hah; i++) {
                printf(" %d", prim[i]);
            }
        }else{
            for (int i = (hah- (2*n-1))/2; i < (hah + (2*n-1))/2; i++) {
                printf(" %d", prim[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    getPrim();
    while (scanf("%d%d", &m, &n) != EOF) {
        printf("%d %d:", m, n);
        solve();
        printf("\n");
    }

    return 0;
}
