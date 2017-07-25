/*************************************************************************
	> File Name: zxs.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Mon 13 Mar 2017 06:59:43 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

struct segTree {
    int lt, rt, begin, end;
    LL sum, tag;
} ret[800010];
int l, r, rt[100010], a[100010], cnt, now, n, m, ct;
char op;


void init(int &i, int lt, int rt) {
    ret[++cnt] = ret[i];
    i = cnt;
    ret[i].begin = lt;
    ret[i].end = rt;
    if (lt == rt) {
        ret[i].sum = a[lt];
        return;
    }
    int mid = (lt+rt)>>1;
    init(ret[i].lt, lt, mid);
    init(ret[i].rt, mid+1, rt);
    ret[i].sum=ret[ret[i].lt].sum+ret[ret[i].rt].sum;
    return;
}

void update(int &i, int l, int r, int val) {
    ret[++cnt] = ret[i];
    i = cnt;
    ret[i].sum += (min(r, ret[i].end)- max(l, ret[i].begin)+1)*val;
    if (ret[i].begin >= l && ret[i].end <= r) {
        if(ret[i].begin != ret[i].end) {
            ret[i].tag += val;
        }
        return;
    }
    int mid = (ret[i].begin + ret[i].end)>>1;
    if(r <= mid) {
        update(ret[i].lt, l, r, val);
    } else if(l > mid) {
        update(ret[i].rt, l, r, val);
    } else {
        update(ret[i].lt, l, r, val);
        update(ret[i].rt, l, r, val);
    }
}

LL query(int i,int l,int r)
{
    if(ret[i].begin>=l && ret[i].end<=r)
        return ret[i].sum;
    LL tmp=(min(r,ret[i].end)-max(l,ret[i].begin)+1)*ret[i].tag;
    int mid=(ret[i].begin+ret[i].end)>>1;
    if(r<=mid)
        tmp+=query(ret[i].lt,l,r);
    else  if(l>mid)
        tmp+=query(ret[i].rt,l,r);
    else 
        tmp+=query(ret[i].lt,l,r)+query(ret[i].rt,l,r);    
    return tmp;
}

int main() {
//    ios::sync_with_stdio(false); 
    bool  b = 0;
    while(scanf("%d%d",&n, &m) != EOF) {
        if(b) {
            printf("\n");
        } else {
            b = 1;
        }
        now  = cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        init(rt[now], 1, n);
        for (int i = 1; i <= m; i++)  {
            scanf(" %c", &op);
            if(op == 'C') {
                now++;
                scanf("%d%d%d", &l, &r, &ct);
                update(rt[now] = rt[now-1], l, r, ct);
            }
            if(op == 'Q') {
                scanf("%d%d",&l, &r);
                printf("%lld\n", query(rt[now], l, r));
            }
            if(op == 'H') {
                scanf("%d%d%d",&l, &r, &ct);
                printf("%lld\n", query(rt[ct], l, r));
            }
            if (op == 'B') {
                scanf("%d", &now);
                cnt = rt[now+1]-1;
            }
        }
    }
    
	return 0;
}
