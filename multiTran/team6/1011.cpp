/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Thu Aug 10 2017 12:44:16
************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int t, n;
int num[105][8];

int main() {
    ios::sync_with_stdio(false);
    // freopen("./in.txt", "r", stdin);
    cin>> t;
    while (t--) {
        int a, b, c, d, e, f, g;
        cin>> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 7; j++)
                cin>> num[i][j];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            d = num[i][4]-num[i][7];
            e = num[i][5]-num[i][7];
            f = num[i][6]-num[i][7];
            g = num[i][7];
            a = num[i][1] - d-f-g;
            b = num[i][2] - d-e-g;
            c = num[i][3] - e-f-g;
            if (a < 0||b<0||c<0||d<0||e<0||f<0||g<0) {
                continue;
            }
            if (a>100||b>100||e>100||f>100||c>100||d>100||g>100)
                continue;
            int sum = a+b+c+d+e+f+g;
            if (sum > ans) {
                ans = sum;
            }
        }
        cout<< ans<< endl;
    }

    return 0;
}
