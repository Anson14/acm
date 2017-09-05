/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Wed Aug 16 2017 18:41:7
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
LL n, k;
LL biao[100];

void get_num_of_floor() {
	clr(biao);
	biao[0] = 1;
	LL s = 1;
	for (int i = 1; i < 60; i++) {
		s *= k;
		biao[i] = biao[i-1] + s;
	}
}

int main() {
    ios::sync_with_stdio(false);
	// freopen("in.txt", "r", stdin);
	cin>> t;
	while (t--) {
		cin>> n>> k;
		get_num_of_floor();
		LL ju = 0;
		LL ans = 0;
		for (int i = 0; i < 60; i++) {
			ju += biao[i];
			if (ju > n) {
				break;
			}
			
		}
	}

    return 0;
}
