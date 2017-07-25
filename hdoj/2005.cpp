/*************************************************************************
> File Name: 2005.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: Wed 24 May 2017 10:41:53 AM CST
************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;


char s[10];
int main() {
    ios::sync_with_stdio(false);
    while (~scanf("%s", s)) {
        const char *d = "/";
        char *a = strtok(s, d);
        int y = a[3]-'0' + (a[2]-'0')*10 + (a[1]-'0')*100 + (a[0]-'0')*1000;
        char *b = strtok(NULL, d);
        int len = strlen(b);
        int m = 0, cnt = 1;
        while (len) {
            m += (b[len-1]-'0')*cnt;
            cnt *= 10;
            len--;
        }
        char *c = strtok(NULL, d);
        len = strlen(c);
        int da = 0;
        cnt = 1;
        while (len) {
            da += (c[len-1]-'0')*cnt;
            cnt *= 10;
            len--;
        }
        bool flag = false;
        if ((y &4 == 0 && y %100 != 0) || (y %400 == 0)) {
            flag = true;
        }
        int ans = 0;
        while (--m) {
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
                ans += 31;
            } else if (m == 2 && flag) {
                ans += 29;
            } else if (m == 2  &&!flag) {
                ans += 28;
            } else if (m == 4 || m == 6 || m == 9 || m == 11) {
                ans += 30;
            }
        }
        ans += da;
        printf("%d\n", ans);
    }

    return 0;
}
