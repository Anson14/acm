/*************************************************************************
	> File Name: d.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Mon 01 May 2017 11:47:16 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 10000

int prim[MAXN+5];
int ans, n, cnt = 0, x;
        int bb = 0;

void getprim() {
    clr(prim);
    for(int i=2;i<=MAXN;i++)
    {
        if(!prim[i]) prim[++prim[0]]=i;
        for(int j=1; j<=prim[0] &&prim[j]<=MAXN/i; j++)
        {
            prim[prim[j]*i]=1;
            if(i%prim[j]==0) break;
        }
    }  
}

void solve(int t) {
    if (t < 2) {
        printf("0\n");
    }
    //寻找到第一个比他大或相等的素数
    int bound = lower_bound(prim+1, prim + prim[0]+1, t)-prim;
    if (prim[bound] == t) {
        ans++;
    }

    for (int i = 1; i < bound; i++) {
        cnt = 0;
        for (int j = i; j < bound; j++) {
            cnt += prim[j];
            if(cnt == t) {
                ans++;
                break;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
	ios::sync_with_stdio(false);
    getprim();
    while (scanf("%d", &n) != EOF && n)  {
        cnt = 0;
        ans = 0;
        solve(n);
    }

	return 0;
}
