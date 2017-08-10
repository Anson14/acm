/*************************************************************************
    > File Name: 1008.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月09日 星期三 16时04分16秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
//#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 10005

int t, n, m;
LL b[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        cin >> b[i];
    }
    while (n) {
        int find = 0;
        for (int i = 1; i <= m; i++) {
            if (b[i]) {
                find = i;
                break;
            }
        }
        cout << find;
        if (n == 1)
            cout << endl;
        else cout << " ";
        for (int i = find; i <= m; i++) {
            b[i] -= b[i - find];
        }
        n--;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
