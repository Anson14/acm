/*************************************************************************
  > File Name: tran.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年07月27日 星期四 19时17分45秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
//#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 1005

struct a {
    int n;
} ss;

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    //cin>> a;

    
    int ca = 0;
    cin >> ca;
    while (cin >> a) {
        //if (a == 0 && b == 0) {
        //reak;
        //}
        //if (a == 0) {
        //break;
        //}
        int sum = 0;
        for (int i = 0; i < a; i++) {
            cin >> b;
            sum += b;
        }

        cout <<  sum << endl;
        if (ca != 1) {
            cout << endl;
            ca--;
        }
    }
    return 0;
}
