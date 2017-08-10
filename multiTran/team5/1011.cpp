/*************************************************************************
    > File Name: 1011.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月08日 星期二 12时17分59秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#define LL long long
#define clr(x) memset(x, 0, sizeof(x))
using namespace std;
#define MAXN 100005

int t, n, k;
int a[MAXN];

int main() {
  ios::sync_with_stdio(false);
  // freopen("in.txt", "r", stdin);
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    ;
    int ans = n;
    bool flag = false;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] - a[i - 1] > k) {
        ans = (n - i);
        flag = true;
        break;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
