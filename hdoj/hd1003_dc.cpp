/*************************************************************************
	> File Name: hd1003_dc.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Tue 09 May 2017 11:41:29 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

// 获取[x,y)中的最大连续和
int maxSum(int *a, int x, int y) {
    int v, l, r, maxs;
    if (y - x == 1) {   //r如果当前求的区间只有一个值的话那么就返回出那个值
        return a[x];
    }
    int m = x + (y-x)/2;
    maxs = max(maxSum(a, x, m), maxSum(a, m, y));    //递归的求出二分后的子集中的最大连续和
    v = 0;
    l = a[m-1];
    for (int i = m-1; i >= x; i--) {   //求出当前序列的左半部分的最大连续和
        l = max(l,v+=a[i]);
    }
    v = 0;
    r = a[m];
    for (int i = m; i < y; i++) {
        r = max(r, v+= a[i]);
    }
    return max(maxs, l+r);   //把分开求的最大连续和和合并在一起的最大连续和进行比较
}

int main() {
	ios::sync_with_stdio(false);
    int n;
    int a[100005];
    scanf("%d", &n);
    for (int cnt = 1; cnt <= n; cnt++) {
        int p;
        scanf("%d", &p);
        clr(a);
        for (int i = 0; i < p; i++) {
            scanf("%d", &a[i]);
        }
        printf("Case %d:\n", cnt);
        printf("%d\n", maxSum(a, 0, p));
    }

	return 0;
}
