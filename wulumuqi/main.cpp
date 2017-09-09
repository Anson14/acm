/*************************************************************************
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年09月09日 星期六 12时09分44秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>

#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 10005

int main() {
//    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int T;
//    cin>> T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) {
        LL a;
//        cin>> a;
        scanf("%lld", &a);
//        cout<< "Case #"<< ca<< ": ";
        printf("Case #%d: ", ca);
        for (LL i = a;; i++) {
            if (i % 2 != 0 && i == (LL) sqrt(i) * (LL) sqrt(i)) {
                LL b = (i + 1) / 2;
                if (b == (LL) sqrt(b) * (LL) sqrt(b)) {
//                    cout<< i<< endl;
                    printf("%d\n", i);
                    break;
                }
                b = (i - 1) / 2;
                if (i - 1 < a)
                    continue;
                if (b == (LL) sqrt(b) * (LL) sqrt(b)) {
//                    cout<< 2*b<< endl;
                    printf("%d\n", 2 * b);
                    break;
                }
            }
        }
    }
}
