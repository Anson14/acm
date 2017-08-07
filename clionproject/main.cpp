/*************************************************************************
> File Name: 1166.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年08月04日 星期五 20时19分35秒
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
#define INF 99999999

int arry[MAXN];

struct segTreeNode {
    int val;
    int left, right;
    int mark;
} segTree[MAXN * 4];

void build(int node, int tstart, int tend) {
    //此处以及一下的函数的node均表示当前操作的子树的根节点
    segTree[node].mark = 0;
    segTree[node].left = tstart;
    segTree[node].right = tend;
    if (tstart == tend) {
        //如果找到了叶子节点，就把叶子节点对应的值放到里面去
        segTree[node].val = arry[tend];
    } else {
        int mid = (tstart + tend) / 2;
        build(node * 2, tstart, mid);
        build(node * 2 + 1, mid + 1, tend);
        //这是在递归回来之后，这时候我已经建立好了其左右子树了
        segTree[node].val = min(segTree[node * 2].val, segTree[node * 2 + 1].val);
    }
}

void pushDown(int node) {
    if (segTree[node].mark != 0) {
        //设置左右孩子节点的标志域
        segTree[node * 2].mark += segTree[node].mark;
        segTree[node * 2 + 1].mark += segTree[node].mark;
        //根据标志域设置孩子节点的值，因为我们所求的是min
        //所以每个区间里面的元素均应该加上这个值
        segTree[node * 2].val += segTree[node].mark;
        segTree[node * 2 + 1].val += segTree[node].mark;

        segTree[node].mark = 0;
    }
}

int query(int node, int qstart, int qend) {
    //其中
    //[segTree[node].left, segTree[node].right] means the interval(区间) you are scaning now
    //[qstart, qend] means the interval you want to query
    if (segTree[node].left > qend || segTree[node].right < qstart) {
        return INF;
    }
    if (qstart <= segTree[node].left && qend >= segTree[node].right) {
        return segTree[node].val;
    }
    pushDown(node);
    return min(query(node * 2, qstart, qend),
               query(node * 2 + 1, qstart, qend));
}

void updateSeg(int node, int ustart, int uend, int addVal) {
    if (ustart > segTree[node].right || uend < segTree[node].left) {
        return;
    }
    if (ustart <= segTree[node].left && segTree[node].right <= uend) {
        segTree[node].mark += addVal;
        segTree[node].val += addVal;
        return;
    }
    pushDown(node); //将当前的标记传下去
    int mid = (segTree[node].left + segTree[node].right) / 2;
    updateSeg(node * 2, ustart, mid, addVal);
    updateSeg(node * 2 + 1, mid + 1, uend, addVal);
    segTree[node].val = min(segTree[node * 2].val, segTree[node * 2 + 1].val);
}

void updateOne(int node, int index, int addVal) {
    //index: 待更新节点在原始数组中的下标
    //更新的值
    if (segTree[node].left == segTree[node].right) {
        segTree[node].val = addVal;
        return;
    }
    //判断需要在哪个子树中更新
    int mid = (segTree[node].left + segTree[node].right) / 2;
    if (index <= mid) {
        updateOne(node * 2, index, addVal);
    } else {
        updateOne(node * 2 + 1, index, addVal);
    }
    //回溯完毕之后就可以更新左右子树节点上的值了
    segTree[node].val = min(segTree[node * 2].val,
                            segTree[node * 2 + 1].val);
}

int main() {
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int T = 0;
    int n = 0;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        clr(arry);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arry[i]);
        }
        build(1, 1, n);
        for (int i = 1; i <= 4 * n; i++) {
            printf("%d:  %d\n", i, segTree[i].val);
        }
        char s[10];
        printf("Case %d:\n", cas);
        while (~scanf("%s", s) && s[0] != 'E') {
            printf("\n");
            int i, j;
            scanf("%d %d", &i, &j);
            if (s[0] == 'Q') {
                printf("%s   %d  %d\n", s, i, j);
                printf("%d\n", query(1, i, j));
                continue;
            }
            if (s[0] == 'A') {
                updateSeg(1, i, i, j);
                printf("%s   %d  %d\n", s, i, j);
                for (int i = 1; i <= 4 * n; i++) {
                    printf("%d:  %d\n", i, segTree[i].val);
                }
            }
            if (s[0] == 'S') {
                updateSeg(1, i, i, -j);
                for (int i = 1; i <= 4 * n; i++) {
                    printf("%d:  %d\n", i, segTree[i].val);
                }
            }
        }
    }

    return 0;
}

