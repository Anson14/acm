/*************************************************************************
	> File Name: xx.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Fri 19 May 2017 04:31:00 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;


int main()
{
    //freopen("in.txt","r",stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        int a[100005];
        clr(a) ;
        char str[100005];
        char pre = '(';
        scanf("%s", str);
        char now;
        int cnt = 1, qwe = 1;;
        a[1] = cnt;
        for (int i = 2; i <= n; i++) {
            now = str[qwe++];
            if (pre == '(' && now == '(') {
                a[i] = ++cnt;
            } else if (pre == '(' && now == ')') {
                a[i] = -cnt;
            } else if (pre == ')' && now == '(') {
                a[i] = cnt;
            } else if(pre == ')' && now == ')'){
                cnt--;
                a[i] = -cnt;
            }
            pre = now;
        }
        int z = 0, x = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &z, &x);
            if (z == 1 && x == n) {
                printf("No\n");
                continue;
            }
            if((a[z] > 0 && a[x] > 0) || (a[z] < 0 && a[x] < 0)) {
                printf("Yes\n");
            } else if (abs(a[z]) - abs(a[x]) == 0 ) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
