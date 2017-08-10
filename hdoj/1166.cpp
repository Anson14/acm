/*************************************************************************
    > File Name: 1166.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
<<<<<<< HEAD
  > Created Time: 2017年08月08日 星期二 21时14分56秒
=======
  > Created Time: 2017年08月09日 星期三 11时16分03秒
>>>>>>> 643520228b11d0faad7e1a64e1032cdd914f82c4
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
<<<<<<< HEAD
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
=======
#define MAXN 50005

struct segTree {
    int val;
} node[MAXN*4];
int n;
int arry[MAXN];

void build(int root, int left, int right) {
    if (left == right) 
        node[root].val = arry[left];
    else {
        int mid = (left+right)/2;
        build(root*2, left, mid);
        build(root*2+1, mid+1, right);
        node[root].val = node[root*2].val + node[root*2+1].val;
    }
}

void update(int root, int left, int right, int index, int addval) {
    if (left == right)    {
        node[root].val += addval;
        return;
    } else {
        int mid = (left+right)/2;
        if (index <= mid) {
            update(root*2, left, mid, index, addval);
        } else {
            update(root*2+1, mid+1, right, index, addval);
        }
        node[root].val = node[root*2].val + node[root*2+1].val;
    }
}

int query(int root, int left, int right, int start, int end) {
    if (left >= start && right <= end) {
        return node[root].val;
    }
    int mid = (left+right)/2;
    int ret = 0;
    if (start <= mid)
        ret += query(root*2, left, mid, start, end);
    if (end > mid)
        ret += query(root*2+1, mid+1, right, start, end);
    return ret;
>>>>>>> 643520228b11d0faad7e1a64e1032cdd914f82c4
}


int main() {
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
<<<<<<< HEAD
=======
    int t;
    char s[10];
    //scanf("%d", &t);
    cin>> t;
    for (int cas = 1; cas <= t; cas++) {
        //scanf("%d", &n);
        cin>> n;
        for (int i = 1; i <= n; i++) {
            //scanf("%d", &arry[i]);
            cin>> arry[i];
        }
        build(1, 1, n);
        //printf("Case %d:\n", cas);
        cout<< "Case "<< cas<< ":"<< endl;
        //while (~scanf("%s", s) && s[0] != 'E') {
        while(cin>> s && s[0] != 'E') {
            int i, j;
            int ans = 0;
            //scanf("%d %d", &i, &j);
            cin>> i>> j;
            if(s[0] == 'Q') {
                ans = query(1, 1, n, i, j);
                //printf("%d\n", ans);
                cout<< ans<< endl;
            }
            if (s[0] == 'S') {
                update(1, 1, n, i, -j);
            }
            if (s[0] == 'A') {
                update(1, 1, n, i, j);
            }
        }
    }

>>>>>>> 643520228b11d0faad7e1a64e1032cdd914f82c4
    return 0;
}
