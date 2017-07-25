/*************************************************************************
	> File Name: d_poj3045.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Sun 14 May 2017 11:59:08 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 50005

int n;
struct Cow {
    int weight, strngth;
    bool operator < (const Cow& other) const {
        return other.strngth + other.weight < strngth + weight;    //力气越大体重越大的牛应该放在越下面。
    }
}cow[MAXN];

int main() {
	ios::sync_with_stdio(false);
    while (~scanf("%d", &n)) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &cow[i].weight, &cow[i].strngth);
            sum += cow[i].weight;
        }
        sort(cow+1, cow+n+1);
        int ans = 0x80808080;     //此处很郁闷！！！
        int s[n+1];
        for (int i = 1; i <= n; i++) {
            sum -= cow[i].weight;
            //ans = max(ans, sum - cow[i].strngth);
            s[i] = sum-cow[i].strngth;
        }
        sort(s+1, s+n+1);
        ans = s[n];
        
        printf("%d\n", ans);

        //int l = 0, r = sum;
        //while (l < r) {
            //mid  = l + (r-l)>>1;
            //if ()
        //}
    }

	return 0;
}
