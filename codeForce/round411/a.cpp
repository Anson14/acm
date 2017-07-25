/*************************************************************************
	> File Name: a.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 04 May 2017 11:00:38 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int m, n;

int main() {
	ios::sync_with_stdio(false);
    while(scanf("%d%d", &m, &n) != EOF) {
        if (m == n) {
            printf("%d\n", m);
        }else
        printf("2\n");
    }

	return 0;
}
