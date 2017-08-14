/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Fri Aug 11 2017 16:28:28
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

complex<double> x, y;

double r;

complex<double> divide(complex<double> a,complex<double> b) {
    complex<double> r = a + b;
    if(a == -b) r = complex<double>(-a.imag(), a.real());
    return r / abs(r);
}

int main() {
    // ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    int t;
    // cout.setf(ios::showpoint);
    // cin>> t;
    scanf("%d", &t);
    while(t--) {
        double x1,y1,x2,y2;
        // cin>> r;
        // cin>> x1>> y1;
        // cin>> x2>>y2;
        scanf("%lf", &r);
        scanf("%lf%lf\n%lf%lf",&x1,&y1,&x2,&y2);
        x = complex<double>(x1,y1);
        y = complex<double>(x2,y2);
        if (x == y) {
            printf("%.7f\n", (r-abs(x))*2);
            // cout<<setprecision(8)<<(r-abs(x))*2<< endl;
        } else {
            // if (abs(x) == r || abs(y) == r) {
               if (sqrt(norm(x)-norm(x-y)/4)*r<norm(x)) {
                printf("%.7f\n", abs(x*(r*r/norm(x))- y*(r*r/norm(y))*abs(x)/r));
                // cout<<setprecision(8)<< abs(x*(r*r/norm(x))- y*(r*r/norm(y))*abs(x)/r)<< endl;
                continue;
            }
            printf("%.7f\n", 2*abs(divide(x,y)*r-y));
            // cout<< setprecision(8)<< 2*abs(divide(x,y)*r-y)<< endl;
        }
    }

    return 0;
}
