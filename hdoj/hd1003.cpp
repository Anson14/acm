/*************************************************************************
	> File Name: hd1003.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Fri 05 May 2017 08:27:37 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int cnt;
int a[MAXN], sum[MAXN];

int main() {
	ios::sync_with_stdio(false);
    scanf("%d", &cnt);
    for (int x = 1; x <= cnt; x++) {
        int n = 0;
        scanf("%d", &n);
        //clr(a);
        //clr(sum);
        int ans = 0;
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] += sum[i-1] + a[i];
        }
        int s = 0, b = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = i; j <= n; j++) {
                //ans = max(ans, sum[j] - sum[i-1]);
                if(ans < sum[j] - sum[i-1]) {
                    s = i; b = j;
                    ans = sum[b] - sum[s-1];
                }

            }
        }
        printf("Case %d:\n", x);
        printf("%d %d %d\n\n", ans, s, b);
    }

    return 0;
}
