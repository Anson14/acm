/*************************************************************************
	> File Name: lg.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Fri 31 Mar 2017 07:16:59 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
#define MAXN 101
using namespace std;

bool a[MAXN][MAXN];
bool used[MAXN];
int cn, bestn, p, e;

void dfs(int i) {
    bool flag;
    if (i > p) {
        bestn = cn;
        //printf("%d\n", bestn);
        for (int j = 1; j <= p; j++) {
            if (used[j]) {
                printf ("%d ", j);
            }
        }
        printf ("\n");
        return;
    }
    flag = true;
    for (int j = 1; j < i; j++) {
        if (used[j] && !a[j][i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cn++;
        used[i] = true;
        dfs(i+1);
        cn--;
    }
    if (cn+p-i > bestn) {
        used[i] = false;
        dfs(i+1);
    }
}

int main() {
    int num, u, v;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    scanf("%d", &num);
    while(num--) {
        clr(a);
        clr(used);
        scanf ("%d%d", &p, &e);
        for (int i = 0; i < e; i++) {
            scanf("%d%d", &u, &v);
            a[u][v] = true;
            a[v][u] = true;
        }
        cn = bestn = 0;
        dfs(1);
        //printf ("%d\n", bestn);
    }


	return 0;
}
