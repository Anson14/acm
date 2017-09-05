/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Tue Aug 22 2017 12:30:3
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

int m;
int a[505];
int ka[505][505];

int main() {
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    while (cin>> m) {
		clr(ka);
		int n = (sqrt(1+8*m)-1)/2;
        for (int i = 0; i < m; i++) {
            cin>> a[i];
        }
        sort(a, a+m);
        int b[n];
        b[0] = a[0];
        b[1] = a[1];
        int p = 2;
        for (int i = 2; i < m; i++) {
            bool flag = false;
            if (p == n) {
                break;
            }
            for (int j = 0; j < p; j++) {
                for (int k = j+1; k < p; k++) {
                    if (b[j] + b[k] == a[i] && !ka[j][k]) {
						flag = true;
						ka[j][k]= true;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                continue;
            } else {
                b[p++] = a[i];
            }
        }
        for (int i = 0; i < n; i++) {
			cout<< b[i];
			if (i == n-1)
				cout<< endl;
			else 
				cout<< " ";
        }
    }

    return 0;
}
