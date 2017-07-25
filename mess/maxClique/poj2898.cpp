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
#define MAX  130

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
    freopen("2898.in", "r", stdin);
    int m;
    cin>> n>> m;
    for (int i = 0; i < m; i++) {
        int kk, uu;
        cin>> kk>> uu;
        map[kk][uu] = 1;
        map[uu][kk] = 1;
    }
        ans = 0;
        dfs(0,1);
        //printf("%d\n", ans);
    cout<< ans<< endl;

	return 0;
}
