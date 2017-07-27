/*************************************************************************
    > File Name: a.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年07月25日 星期二 12时08分41秒
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
    int n;
    int i = 1;
    while (cin>> n) {
        int a = (int)floor(n*log10((long double)2));

        cout<<"Case #"<< i++<< ": "<< a<< endl;
    }

    return 0;
}
