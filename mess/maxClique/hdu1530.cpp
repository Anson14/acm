/*************************************************************************
	> File Name: hdu1530.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 12 Apr 2017 10:20:22 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAX  60

int map[MAX][MAX];
int set[MAX];
int n, ans;

bool isClique(const int end, const int point) {
    for (int i = 1; i < end; i++) {
        if (!map[ set[i] ][point]) {
            return false;
        }
    }
    return true;
}

void dfs(int depth, int now) {
    if (depth + n - now + 1 <= ans) {
        return;
    }
    for (int i = now; i <= n; i++) {  //这里面是当前节点开始寻找，找到能够加入团的节点
        if (isClique(depth+1, i)) {
            set[depth+1] = i;
            dfs(depth+1, i+1);
        }
    }
    if (depth > ans) {
        ans = depth;
    }
}

int main() {
	ios::sync_with_stdio(false);
    //freopen("1530.in", "r", stdin);
    while(scanf("%d", &n) != EOF && n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        ans = 0;
        int dp[MAX];
        dfs(0,1);
        clr(dp);
        ans=0;
        dp[n]=1;
        for (int i = n-1;i>=1;i--)
        {
            set[1]=i;
            dfs(1,i+1);
            dp[i]=ans;
        }
        printf("%d\n",dp[1]);
    }

	return 0;
}