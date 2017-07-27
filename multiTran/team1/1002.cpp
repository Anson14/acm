/*************************************************************************
    > File Name: 1002.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年07月25日 星期二 20时31分38秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
//#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100020

int sum[MAXN], ban[MAXN], power[MAXN];
int num[26][MAXN];
int a[26];
char str[MAXN];
int n, L, ca = 1;

const int Q = 1e9+7;

bool cmp (int A, int B) {
    for (int i = L-1; i >= 0; i--) {
        if (num[A][i] != num[B][i]) {
            return num[A][i] < num[B][i];
        }
    }
    return false;
}

void solve() {
    clr(num);
    clr(ban);
    clr(sum);
    L = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int len = strlen(str);
        if (len > 1)
            ban[str[0]-'a'] = 1;
        reverse(str, str+len);
        for (int j = 0; j < len; j++) {
            num[str[j]-'a'][j]++;
            //此处表示把j所指的字母的权值（也就是其幂数）直接add到sum数组里面，方便以后的求和运算;
            sum[str[j]-'a'] += power[j];
            if (sum[str[j]-'a'] >= Q) {
                sum[str[j]-'a'] -= Q;
            }
        }
        L = max(L, len);
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < L; j++) {
            num[i][j+1] += num[i][j]/26;
            num[i][j] %= 26;
        }
        while (num[i][L]) {
            num[i][L+1] += num[i][L]/26;
            num[i][L++] %= 26;
        }
        a[i] = i;
    }

    sort(a, a+26, cmp);
    int val = 0;
    int zero = -1, now = 25;
    for (int i = 0; i < 26; i++) {
        if (!ban[a[i]]) {
            zero = a[i];
            break;
        }
    }
    for (int i = 25; i >= 0; i--) {
        if (zero != a[i]) {
            val += (LL)now*sum[a[i]]%Q;
            val %= Q;
            now--;
        }
    }
    printf("Case #%d: %d\n", ca++, val);

}

int main() {
    ios::sync_with_stdio(false);
    //freopen("1002.in", "r", stdin);
    power[0] = 1;
    for (int i = 0; i < MAXN-1; i++) {
        power[i+1] = (LL)power[i]*26%Q;
    }
    while(~scanf("%d", &n)) {
        solve();
    }

    return 0;
}
