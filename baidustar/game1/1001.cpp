/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Sat Aug 12 2017 14:43:0
************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int t, b;

int num(int n){ //返回的是因子总数
    int count=2;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            if(i==sqrt(n) && n/i==i){ //如果两因子相同，则只加1
                 count++;   
            }
            else count+=2;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    cin>> t;
    while (t--) {
        cin>> b;
        if (b==1 || b==2) {
            cout<< 1<< endl;
            continue;
        }
        cout<< num(b-1)<< endl;
    }

    return 0;
}
