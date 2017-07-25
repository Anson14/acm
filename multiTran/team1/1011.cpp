/*************************************************************************
> File Name: 1011.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月25日 星期二 13时00分16秒
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

int k = 0;
LL val;
LL a[26];
string s[100005];

int fun(char a) {
    return (int)(a-'a');
}

int main() {
    ios::sync_with_stdio(false);
    freopen("1011.in", "r", stdin);
    int ca = 1;
    while (cin >> k){
        clr(a);
        val = 0;
        for (int i = 0; i < k; i++) {
            cin>> s[i];
            for (int j = s[i].length()-1; j >= 0; j--) {
                int m = s[i].length()-j-1;
                while(m--) {
                    a[fun(s[i][j])] *= 26;
                    if (fun(s[i][j]) > 1000000007) {
                        a[fun(s[i][j])] %= 1000000007;
                    }
                }
            }
        }

        cout<< "Case #"<< ca++<< ": "<< val<< endl;
    }
    return 0;
}
