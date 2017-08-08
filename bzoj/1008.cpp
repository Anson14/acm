/*************************************************************************
    > File Name: 1008.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月04日 星期五 16时17分57秒
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
#define MAXN 1005
const int mod = 100003;

LL qpow(LL a,LL b)
{
    LL c=1,d=a%mod;
    while (b>0)
    {
        if (b&1)
         c=(c%mod*d%mod)%mod;
        b>>=1;
        d=(d%mod*d%mod)%mod;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
    LL m, n;
    while (~scanf("%lld %lld", &m, &n)) {
        LL ans = qpow(m,n)%mod - m*qpow(m-1, n-1)%mod;
        if (ans < 0)
            ans += mod;
        printf("%lld\n", ans);
    }
    return 0;
 }
