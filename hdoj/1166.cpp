/*************************************************************************
    > File Name: 1166.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年08月08日 星期二 21时14分56秒
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

struct segTree {
    int val;
} node[MAXN * 4];

int arry[MAXN];

void build(int root, int left, int right) {
    if (left == right) {
        node[root].val = arry[left];
    } else {
        int mid = (left + right) / 2;
        build(root * 2, left, mid);
        build(root * 2 + 1, mid + 1, right);
        node[root].val = min(node[root * 2].val, node[root * 2 + 1].val);
    }
}

void update(int root, int left, int right, int index, int addval) {
    if (left == right) {
        node[root].val += addval;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    return 0;
}
