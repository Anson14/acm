/*************************************************************************
    > File Name: 1003.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月02日 星期三 10时35分02秒
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
#define MAXN 500005

int T, n, k;
int num[MAXN], pos[MAXN];
int s[MAXN], t[MAXN];
int pre[MAXN], ne[MAXN];


void earse(int x) {
    int pp = pre[x];
    int nn = ne[x];
    if (pp) 
        ne[pp] = nn;
    if (nn<=n) 
        pre[nn] = pp;
    pre[x] = ne[x] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
            pos[num[i]] = i;
        }
        LL ans = 0;
        clr(pre);clr(ne);
        for (int i = 1; i <= n; i++) {
            pre[i] = i-1;
            ne[i] = i+1;
        }
        for (int i = 1; i <= n-k+1; i++) {
            int p = pos[i];
            int s0 = 0, t0 = 0;
            for (int x = p; x && s0 <= k+1; x = pre[x]) {
                s[++s0] = x;
            }
            for (int x = p; x != n+1 && t0 <= k+1; x = ne[x]) {
                t[++t0] = x;
            }
            s[++s0] = 0;
            t[++t0] = n+1;
            for (int y = 1; y < s0; y++) {
                //if (k+1-y<=t0-1) {
                    //ans += i;
                    //printf("%d\n", ans);
                //}
                if(k+1-y<=t0-1&&k+1-y>=1){
                    ans+=(t[k+1-y+1]-t[k+1-y])* 1LL*(s[y]-s[y+1])*i;
                }
            }
            earse(p);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
