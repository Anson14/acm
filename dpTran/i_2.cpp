/*************************************************************************
    > File Name: i_2.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月09日 星期三 16时48分53秒
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

int n, now, last, sum;
int defeat[MAXN];

int main() {
    // ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    sum = 1;
    defeat[0] = 0;
    int ans = 0;
    while(cin>> n) {
        sort(defeat, defeat+sum);
        for (int i = 0; i < n; i++) {
            cin>> now;
        }
    }

    return 0;
}
