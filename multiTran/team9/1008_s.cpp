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
        int p = 1;
        cout<< a[0];
        for (int i = 1; i < m; i++) {
            cout<< " "<< a[i];
            b[p++] = a[i];
            if (p == n) {
                break;
			}
			for (int j = 0; j < p; j++) {
				if (a[i+1] == b[p-1] + b[j]) {
					cout<< "..x: "<< a[i+1];
					i++;
				}
			}
        }
        cout<< endl;
    }

    return 0;
}
