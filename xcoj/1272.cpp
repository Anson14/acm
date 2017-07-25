/*************************************************************************
    > File Name: 1272.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年07月24日 星期一 16时13分56秒
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

LL tran1(LL x) {
    LL num = x;
    LL val = 0;
    int i = 0;
    while (num) {
        LL temp = num%10;
        num /= 10;
        val += pow(8,i++)*temp; 
    }

    return val;
}

LL tran2(LL x) {
    LL num = x;
    LL val = 0;
    int i = 0;
    while (num) {
        LL temp = num%8;
        num /= 8;
        val += pow(10, i++)*temp;
    }
    return val;
}

void solve() {
    LL t, m, n;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &m, &n);
        m = tran1(m);
        n = tran1(n);
        m = tran2(m-n);
        printf("%lld\n", m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();

    return 0;
}
