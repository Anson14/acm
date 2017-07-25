/*************************************************************************
	> File Name: 19_a.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Sat 15 Apr 2017 11:19:35 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

#define MAX 50

int n, k;
int a[MAX];

int main() {
	ios::sync_with_stdio(false);
    bool flag = true;
    int cnt = 0;
    while (scanf ("%d%d", &n, &k) != EOF) {
        clr(a);
        if (k == 1) {
            a[0] = n;
        } else {
            while (n != 1) {
                for (int i = 2; i <=n; i++) {
                    if (n % i == 0) {
                        a[cnt] = i;
                        cnt ++;
                        n /= i;
                        break;
                    }
                }
            }
        }
            if (a[k-1] == 0) {
                printf("-1\n");
            } else {
                if (a[k] != 0) {
                    for (int i = k; i < MAX; i++) {
                        if (a[i] != 0) {
                            a[k-1] *= a[i];
                        }
                    }
                }
                for (int i = 0; i < k; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
            }
    }
	return 0;
}
