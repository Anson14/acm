/*************************************************************************
> File Name: c.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月29日 星期六 19时23分30秒
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
#define MAXN 50020

int t;
char ch[MAXN], All[MAXN];
int SA[MAXN], ranks[MAXN], Height[MAXN], tax[MAXN], tp[MAXN], a[MAXN], n, m;
char str[MAXN];
//ranks[i] 第i个后缀的排名; SA[i] 排名为i的后缀位置; Height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP
//tax[i] 计数排序辅助数组; tp[i] ranks的辅助数组(计数排序中的第二关键字),与SA意义一样。
//a为原串

void RSort() {
    //ranks第一关键字,tp第二关键字。
    for (int i = 0; i <= m; i ++) tax[i] = 0;
    for (int i = 1; i <= n; i ++) tax[ranks[tp[i]]] ++;
    for (int i = 1; i <= m; i ++) tax[i] += tax[i-1];
    for (int i = n; i >= 1; i --) SA[tax[ranks[tp[i]]] --] = tp[i]; //确保满足第一关键字的同时，再满足第二关键字的要求
} //计数排序,把新的二元组排序。

int cmp(int *f, int x, int y, int w) { return f[x] == f[y] && f[x + w] == f[y + w]; }
//通过二元组两个下标的比较，确定两个子串是否相同

void Suffix() {
    //SA
    for (int i = 1; i <= n; i ++)
        ranks[i] = a[i], tp[i] = i;
    m = 127 ,RSort(); //一开始是以单个字符为单位，所以(m = 127)

    for (int w = 1, p = 1, i; p < n; w += w, m = p) {
        //把子串长度翻倍,更新ranks

        //w 当前一个子串的长度; m 当前离散后的排名种类数
        //当前的tp(第二关键字)可直接由上一次的SA的得到
        for (p = 0, i = n - w + 1; i <= n; i ++)
            tp[++ p] = i; //长度越界,第二关键字为0

        for (i = 1; i <= n; i ++)
            if (SA[i] > w)
                tp[++ p] = SA[i] - w;

        //更新SA值,并用tp暂时存下上一轮的ranks(用于cmp比较)
        RSort(), swap(ranks, tp), ranks[SA[1]] = p = 1;

        //用已经完成的SA来更新与它互逆的ranks,并离散ranks
        for (i = 2; i <= n; i ++)
            ranks[SA[i]] = cmp(tp, SA[i], SA[i - 1], w) ? p : ++ p;
    }
    //离散：把相等的字符串的ranks设为相同。
    //LCP
    int j, k = 0;
    for(int i = 1; i <= n; Height[ranks[i ++]] = k)
    for( k = k ? k - 1 : k, j = SA[ranks[i] - 1]; a[i + k] == a[j + k]; ++ k);
    //这个知道原理后就比较好理解程序
}

void Init() {
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i ++) a[i + 1] = str[i];
}

int solve() {
    Suffix();
    LL num = (LL)n*(n+1)/2;
    LL ha = 0;
    for (int i = 1; i <= n; i++) {
        ha += Height[i];
        //printf("  %d\n", Height[i]);
    }
    printf("%lld\n", num-ha);
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        Init();
        solve();
    }

    return 0;
}
