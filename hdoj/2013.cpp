/*************************************************************************
	> File Name: 2013.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 24 May 2017 08:49:37 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int tao(int n) {
    if (n == 1) {
        return 1;
    }
    return (tao(n-1)*2+2);
}

int main() {
	ios::sync_with_stdio(false);
    int n;
    while(~scanf("%d", &n)) {
        printf("%d\n", tao(n));
    }

	return 0;
}
