/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Sat Aug 19 2017 14:4:58
************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int t;
LL L, R;
int l, r;

bool judge(LL a) {
	LL an = 0;
	LL te = a;
	LL c = 10;
	while (te/10) {
		an += te%10;
		an *= c;
		te /= 10;
	}
	an += te%10;
	if (an == a) {
		return true;
	}
	return false;
}

LL tran(LL a, int k) {
	LL ans = 0;
	while (a) {
		
	}
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
	cin>> t;
	for (int ca = 1; ca <= t; ca++) {
		cin>> L>> R>> l>> r;
	}
    return 0;
}
