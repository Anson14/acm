/*************************************************************************
> File Name: 1003.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年08月03日 星期四 13时29分35秒
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
#define MAXN 1000015

const int c = 998244353;
int t;
LL l, r, k, tot, N = MAXN;
int n;
LL p[100010];
bool v[MAXN];
LL f[MAXN], g[MAXN];

void getPrim() {
    for(int i=2;i<N;i++){
        if(!v[i])p[tot++]=i;
        for(int j=0;j<tot&&i*p[j]<N;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}

void solve(LL p) {
    for (LL i = l/p*p; i <= r; i += p) {
        if (i >= l) {
            int o = 0;
            //问一下子为什么要用i-l 这里面i 是p的倍数，所以呢？
            while (f[i-l]%p == 0) {
                o++;
                f[i-l] /= p;
            }
            g[i-l] =1LL* g[i-l] * (o*k+1) % c;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    getPrim();
    scanf("%d", &t);
    while(t--) {
        scanf("%lld %lld %lld", &l, &r, &k);
        n = r-l;
        for (int i = 0; i <= n; i++) {
            f[i] = i+l;
            g[i] = 1;
        }
        for (int i = 0; i < tot; i++) {
            if (1LL*p[i]*p[i] > r) {
                break;
            }
            solve(p[i]);
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (f[i] > 1) {
                g[i] =1LL* (k+1)*g[i]%c;
            }
            ans = (ans+g[i])%c;
        }
        printf("%d\n", ans);
    }

    return 0;
}
