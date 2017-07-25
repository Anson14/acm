/*************************************************************************
	> File Name: b_poj3273.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Fri 12 May 2017 10:19:24 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int n, m;
int a[MAXN];

int main() {
	ios::sync_with_stdio(false);
    while (~scanf("%d%d", &n, &m)) {
        int sum = 0, maxm = 0;;
        for (int i = 0;  i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            maxm = max(maxm, a[i]);
        }
        while (maxm < sum) {
            int mid = (sum+maxm)>>1;
            int s = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                s += a[i];
                if (s > mid) {    //如果s比我们当前判断的值要大的，就把前面的作为一个集合
                    s = a[i];
                    cnt++;
                }
            }
            if (cnt == m-1) {
                maxm = mid+1;
                break;
            }
            if (cnt < m) {
                sum = mid;
            } else {
                maxm = mid+1;
            }
        }
        printf("%d\n", maxm);
    }

	return 0;
}
