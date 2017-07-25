/*************************************************************************
	> File Name: a_hd3258.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Tue 09 May 2017 11:15:41 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath> 
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 50005

int l, n, m;
int d[MAXN+2];

bool judge(int p) {
    int pre = 0;
    int cnt = 0;
    for (int i = 1; i < n+1; i++) {
        if (d[i] - d[pre] < p) {
            cnt++;
        } else {
            pre = i;
        }
    }
    if (d[n+1] - d[pre] < p) {
        cnt++;
    }
    return cnt<=m;
}

int solve() {
    sort(d+1, d+n+1);
    if (judge(l)) {
        return l;
    }
    int ub = 0, rb = l;
    while(rb-ub > 1) {
        int mid = (ub + rb)/2;
        if (judge(mid)) {
            ub = mid;
        } else  {
            rb = mid;
        }
    }
    return ub;
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d%d%d", &l, &n, &m);
    {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &d[i]);
        }
        d[0] = 0; d[n+1] = l;
        printf("%d\n", solve());
    }
    return 0;
}
