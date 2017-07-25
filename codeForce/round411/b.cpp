/*************************************************************************
	> File Name: b.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 04 May 2017 11:10:40 PM CST
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
        for (int i = 0; i < n; i++) {
            if (i % 4 == 0 || i % 4 == 1) {
                printf("a");
            } else {
                printf("b");
            }
        }
        printf("\n");
    }

	return 0;
}
