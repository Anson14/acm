/*************************************************************************
	> File Name: b.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Sat 15 Apr 2017 11:58:45 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAX 100005

int N;
int a[MAX];

int main() {
	ios::sync_with_stdio(false);
    while (scanf("%d", &N) != EOF) {
        clr(a);
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        int mmmo = 100000;
        long int sum = 0;
        for (int i = 0; i < N; i++)  {
            if (a[i] > 0) {
                sum += a[i];
            }
            if (a[i] % 2 != 0)  
                if (abs(a[i]) < mmmo)
                    mmmo = abs(a[i]);
        }
        if (sum % 2 == 0)
            sum -= mmmo;
        printf("%ld\n", sum);
    }

	return 0;
}
