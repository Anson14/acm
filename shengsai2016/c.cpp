/*************************************************************************
	> File Name: c.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 17 May 2017 11:18:28 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int cnt;
double a,b,r,x,y,w,t;
double ans = 0;

int main() {
	ios::sync_with_stdio(false);
    scanf("%d", &cnt);
    while (cnt--) {
        scanf("%lf%lf%lf%lf%lf%lf%lf", &a,&b,&r,&x,&y,&w,&t);
        double x0 = a+r*cos(w*t);
        double y0 = b+r*sin(w*t);
        double d = fabs(a*(y-y0)+b*(x0-x)+y0*(x-x0)-x0*(y-y0))/sqrt((y-y0)*(y-y0)+(x0-x)*(x0-x));
        ans = 2*sqrt(r*r-d*d);
        printf("%.2lf\n", ans);
    }

	return 0;
}
