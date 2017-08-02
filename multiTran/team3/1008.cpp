/*************************************************************************
> File Name: 1008.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年08月01日 星期二 13时09分08秒
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
#define LN 1005

LL k, n;
int a[100];
const LL c = 1000000007;


LL PowerMod(LL a, LL b)
{
    LL ans = 1;
    a = a % c;
    while(b>0) {
        if(b % 2 == 1)
        ans = (ans * a)% c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    int ans = 1;
    while ( cin>> n>> k) {
        n %= c;
        LL res = PowerMod(n, k);
        cout<< "Case #"<< ans++<< ": ";
        cout<< res<< endl;
    }

    return 0;
}
