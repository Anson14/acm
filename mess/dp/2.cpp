/*************************************************************************
	> File Name: 2.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Mon 27 Mar 2017 06:41:29 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
const int INF = 0x3f3f3f3f;
using namespace std;

#define MAX 1005

int c, n;
int a[MAX];
int p[MAX];
int sum[MAX];
int dp[MAX];

int getDp(int i, int j) {
    return min(dp[j] + (sum[i]-sum[j]+10) * p[i], dp[i]);
}

int main() {
	ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    scanf("%d", &c);
    while (c--){
        scanf("%d", &n);
        sum[1] = sum[0] = 0;
        clr(dp);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i], &p[i]);
            getchar();

            dp[i] =  (a[i]+10)*p[i];
            sum[i] = a[i]+sum[i-1];
        }
        for (int i = 1; i <= n; i++) {
            int mini = INF;
            for (int j = 0; j < i; j++) {
                if(dp[j] + (sum[i]-sum[j]+10)*p[i] < mini) {
                    mini = dp[j] + (sum[i]-sum[j]+10) * p[i];
                 }
            }
            dp[i] = mini;
        }        
        printf("%d\n", dp[n]);
    }


	return 0;
}
