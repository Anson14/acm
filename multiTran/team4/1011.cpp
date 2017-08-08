/*************************************************************************
> File Name: 1011.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年08月03日 星期四 12时17分24秒
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
#define MAXN 1005

int t;
int a[8][22];
char x;

int judge(int b)  {
    int o[8];
    clr(o);
    if (a[1][b+1]) o[1] = 1;
    if (a[2][b]) o[2] = 1;
    if (a[2][b+3]) o[3] = 1;
    if (a[4][b+1]) o[4] = 1;
    if (a[5][b]) o[5] = 1;
    if (a[5][b+3]) o[6] = 1;
    if (a[7][b+1]) o[7] = 1;
    //for (int i = 1; i <= 7; i++) {
        //printf("%d ", o[i]);
    //}
    if (o[1] && o[2] && o[3] && o[4] && o[5] && o[6] && o[7]) {
        return 8;
    }
    if (o[1] && o[2] && o[3] && !o[4] && o[5] && o[6] && o[7]) {
        return 0;
    }
    if (!o[1] && !o[2] && o[3] && !o[4] && !o[5] && o[6] && !o[7]) {
        return 1;
    }
    if (o[1] && !o[2] && o[3] && o[4] && o[5] && !o[6] && o[7]) {
        return 2;
    }
    if (o[1] && !o[2] && o[3] && o[4] && !o[5] && o[6] && o[7]) {
        return 3;
    }
    if (!o[1] && o[2] && o[3] && o[4] && !o[5] && o[6] && !o[7]) {
        return 4;
    }
    if (o[1] && o[2] && !o[3] && o[4] && !o[5] && o[6] && o[7]) {
        return 5;
    }

    if (o[1] && o[2] && !o[3] && o[4] && o[5] && o[6] && o[7]) {
        return 6;
    }
    if (o[1] && !o[2] && o[3] && !o[4] && !o[5] && o[6] && !o[7]) {
        return 7;
    }
    if (o[1] && o[2] && o[3] && o[4] && !o[5] && o[6] && o[7]) {
        return 9;
    }




    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        clr(a);
        for (int i = 1; i <= 7; i++) {
            for (int j = 0; j <= 21; j++) {
                scanf("%c", &x);
                if (x == 'X') {
                    a[i][j] = 1;
                }
            }
        }
        //for (int i = 1; i <= 7; i++) {
            //for (int j = 1; j <= 21; j++) {
                //printf("%d",a[i][j]);
            //}
            //printf("\n");
        //}
        int ans1 = judge(1);
        int ans2 = judge(6);
        int ans3 = judge(13);
        int ans4 = judge(18);
        printf("%d%d:%d%d\n",ans1,ans2,ans3,ans4);
    }
    return 0;
}
