/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Tue Aug 15 2017 12:59:20
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
#define MAXN 1005

int main() {
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    int pre = 0;
    int k, n;
    int a[100], b[100], c[100];
    // while (cin>> n>> k) {
    for (k = 2; k < 8; k++) {
        cout<< "n: "<< n<< " k: "<< k<< endl;
        for (n = 1; n < 55; n++) {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                a[i] = 1;
            }
            for (int i = n-1; i > 0; i--) {
                a[(i-1)/k] += a[i];
            }
            for (int i = 0; i < n; i++) {
                cout << a[i]<< " ";
                ans = ans^a[i];
            }
            cout<<" ans: "<<ans<< endl;
            int x = k;
            int p = 1;
            int m = n;
            clr(b);
            while (1) {
                b[p++] = x;           
                if (x > 1000000000) {
                    break;
                }
                x = pow(k, p) + x;             
            }
            int pre = 1;
            int pt = 1;
            clr(c);
            for (int i = p; i >= 0; i--) {
                c[i] = pre;
                pre = pow(k, pt++)+pre;
            }
            for (int i = 0; i < 10; i++) {
                cout<< c[i] << " ";
            }
            // for (int i = 0; i < 50; i++) {
            //     if (b[i+1] > n) {
            //         int zi = n-b[i];
            //         while (i >= 0) {
            //             m = zi / k;

            //         }
            //     }
            // }
            cout<< endl;
        }

        cout<< "\n\n";
    }
    return 0;

}