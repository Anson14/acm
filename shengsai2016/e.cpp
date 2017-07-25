/*************************************************************************
	> File Name: e.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 18 May 2017 08:57:02 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 1005
int n, t, q, c;

struct Arrow {
    int a, b;
    bool operator < (const Arrow& other) const {
        return other.a-other.b > a-b;
    }
} arrow[MAXN];

int main() {
	ios::sync_with_stdio(false);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &arrow[i].a, &c, &arrow[i].b );
            sum += arrow[i].b;
        }
        scanf("%d", &q);
        if (sum > q) {
            //printf("Oh, my god!\n");
            printf("Oh,my god!\n");
            continue;
        }
        sort(arrow, arrow + n);
        int i = 0;
        for (i = 0; i < n; i++) {
            //printf("%d %d %d", arrow[i].a, arrow[i].b, sum);
            sum += arrow[i].a-arrow[i].b;
            if (sum > q) {
                break;
            }
        }
        printf("%d\n", i);
        
    }

	return 0;
}
