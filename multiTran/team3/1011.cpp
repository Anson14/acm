/*************************************************************************
    > File Name: 1011.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月01日 星期二 12时03分16秒
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
#define MAXN 1005

int main() {
    ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
    int t;
    int a[MAXN];
    cin>> t;
    int ans = 0;
    for (int i = 0; i < t; i++) {
        cin >> a[i];
        if (a[i] <= 35) {
            ans++;
        }
    }
    cout<< ans<< endl;

    return 0;
}
