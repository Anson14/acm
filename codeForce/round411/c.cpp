/*************************************************************************
	> File Name: c.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 04 May 2017 11:32:23 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
    while(scanf("%d", &n)!=EOF) {
        printf("%d\n", (n-1)/2);
    }

	return 0;
}
