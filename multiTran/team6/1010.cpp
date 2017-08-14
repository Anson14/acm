/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Fri Aug 11 2017 11:12:4
************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005
bool flag;

int t, n, k;
vector<int> ma[555];

int dfs(int u) {
    int cnt = 0;
    for (int i = 0; i < ma[u].size(); i++) {
        cnt += dfs(ma[u][i]);
        if (cnt>=2)
            flag = 1;
    }
    if (ma[u].size() == 0)
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    cin>> t;
    while (t--) {
        flag = 0;
        cin>> n>> k;
        for (int i = 2; i <= n; i++) {
            int x;
            cin>> x;
            ma[x].push_back(i);
        }
        dfs(1);
        if (!(n%2==0 && k>=n/2-1)) {
            flag = 1;
        }
        if (flag)
            cout<< "Alice\n";
        else
            cout<< "Bob\n";
        for(int i = 1; i <= n; i++) {
            ma[i].clear();
        }
    }

    return 0;
}
