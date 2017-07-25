/*************************************************************************
	> File Name: 2018.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 24 May 2017 09:40:32 PM CST
 ************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>

#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 1000


int main() {
    ios::sync_with_stdio(false);
    int n, a[56] = {2, 3, 4};
    for (int i = 3; i < 56; i++) {
        a[i] = a[i - 1] + a[i - 3];
    }
    while(cin >> n && n) {
        if (n == 1)   //不要问我为什么我也蛮奇怪的这个问题。
            cout << "1" << endl;
        else cout << a[n - 2] << endl;
    }



    return 0;
}
