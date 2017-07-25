/*************************************************************************
	> File Name: 2007.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 24 May 2017 11:23:42 AM CST
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
#define MAXN 1000


int main() {
	ios::sync_with_stdio(false);
    int m, n;
    while (~scanf("%d %d", &m, &n)) {
        if (n < m) {
            swap(m,n);
        }
        int ji = 0, ou = 0;
        for (int i = m; i <= n; i++)  {
            if (i & 1) {
                ji += i*i*i;
            } else 
                ou += i*i;
        }
        printf("%d %d\n", ou, ji);
    }
	return 0;
}
