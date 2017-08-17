/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Sun Aug 13 2017 14:31:20
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

int n;
LL m;

struct node {
    LL start = 0, end = 0;
    LL val;
    LL len;
    bool operator < (const node other) const {
        return start < other.start;
    }
};

int main() {
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    list<node> road;
    while (cin>> n>> m) {
        LL sb = m;
        for (int i = 0; i < n; i++) {
            LL a, b;
            cin>> a>> b;
            node temp;
            temp.start = a;
            temp.end = b;
            temp.val = b-a+1;
            road.push_back(temp);
        }
        road.sort();
        list<node>::iterator i = road.begin(), j;
        for (; i != road.end(); i++) {
            node temp = *i;
            // cout<< "s: "<< temp.start<< " e: "<< temp.end<< " val: "<< temp.val<< " len: "<< temp.len<< endl;
        }
        i = road.begin();
        list<node>::iterator pre = i;
        i++;
        list<node>::iterator end1 = road.end();
        for (; i != end1;) {
            node next = *(i);
            node temp = *pre;
            // cout<< "      s: "<< temp.start<< " e: "<< temp.end<< " val: "<< temp.val<< " len: "<< temp.len<< endl;
            // cout<< "      s: "<< next.start<< " e: "<< next.end<< " val: "<< next.val<< " len: "<< next.len<< endl<< endl;
            if ((temp.start <= next.start && temp.end >= next.start) || next.start - temp.end == 1) {
                (*pre).end = next.end;
                (*pre).val = (*pre).end-(*pre).start+1;
                // cout<< "s: "<< temp.start<< " e: "<< temp.end<< " val: "<< temp.val<< " len: "<< temp.len<< endl;
                // cout<< "s: "<< next.start<< " e: "<< next.end<< " val: "<< next.val<< " len: "<< next.len<< endl;
                i = road.erase(i);
            } else {
                pre = i;
                i++;
            }
        }


        end1--;
        for (i = road.begin(); i != end1;) {
            j = i;
            node temp = *i;
            node next = *(++i);
            (*j).len = next.start - temp.end-1;
            // cout<< "s: "<< temp.start<< " e: "<< temp.end<< " val: "<< temp.val<< " len: "<< temp.len<< endl;
        }
        // cout<< endl;

        for (i = road.begin(); i != road.end(); i++) {
            node temp = *i;
            // cout<< "s: "<< temp.start<< " e: "<< temp.end<< " val: "<< temp.val<< " len: "<< temp.len<< endl;
        }
        // cout<< endl;

        i = road.begin();
        pre = i++;
        node pr = *pre;
        LL ma = 0, ha = pr.val+pr.len;
        m -= pr.len;
        LL oo = 0;
        for (; i != road.end(); i++) {
            // cout<<"   ma: "<<ma<< " ha: " <<ha << " m: "<< m<<endl;
            node temp = *i;
            pr = *pre;
            ha += temp.val;
            
            if (m < 0) {
                m += pr.len;
                pre++;
                ha -= pr.val+pr.len+temp.len;
                continue;
            }
            if (ma+oo < ha) {
                ma = ha;
                oo = m;
            }
            m -= temp.len;
        }
        LL he = 0;
        for (i = road.begin(); i != road.end(); i++) {
            he = max(he, (*i).val);
        }
        ma = max(ma+oo, he+sb);
        for (i = road.begin(); i != road.end();) {
            road.erase(i++);
        }
        cout<< ma<< endl;
   }
    return 0;

}