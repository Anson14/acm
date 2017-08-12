/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Sat Aug 12 2017 15:23:21
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

int main() {
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
	int b;
	while (cin>> b) {
		int ans = 1;
		for (int i = 2; i <b;i++) {
			if (b%i==1)
				ans++;
		}
			cout<< " "<<ans<< endl; 
	}

    return 0;
}
