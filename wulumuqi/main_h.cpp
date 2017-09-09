/*************************************************************************
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年09月09日 星期六 12时09分44秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 10005

int N, M;
struct Ma {
    vector <int> pre, next;
    int length;
}ma[MAXN];

void dfs(int n, int & m) {
    if (ma[n].next.empty()) {
        return;
    }
    m += ma[n].length;
    for (size_t i = 0; i < ma[n].next.size(); i++) {
        dfs(ma[n].next[i], m);
    }
}

void solve() {
    int maxn = 0, p = 0;
    int ele[MAXN];
    for (int i = 1; i <= N; i++) {
        if (ma[i].pre.empty()) {
            ele[p++] = i;
        }
    }
    for (int i = 0; i < p; i++) {
        int temp = 0;
        dfs(ele[i], temp);
        maxn = max(temp, maxn);
    }
    cout<< maxn<< endl;
}

int main() {
    ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
    int T;
    cin>> T;
    while (T--) {
        cin>> N>> M;
        int a, b, c;
        for (int i = 0; i < M; i++) {
            cin>> a>> b>> c;
            ma[a].next.push_back(b);
            ma[b].pre.push_back(a);
            ma[a].length = c;
        }
        solve();
        for (size_t i = 1; i <= N; i++) {
            vector<int>().swap(ma[i].pre);
            vector<int>().swap(ma[i].next);
        }
    }

    return 0;
}
