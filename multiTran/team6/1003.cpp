/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Thu Aug 10 2017 12:15:19
************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 100005

int t, n;

struct nodeT {
    int place;
    LL val;
    bool operator < (nodeT const other) {
        return val > other.val;
    }
} a[MAXN];

int main() {
   ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
   cin>> t;
   while (t--) {
       cin>> n;
       for (int i = 1; i <= n; i++) {
           cin>> a[i].val;
           a[i].place = i;
       }
       sort(a+1, a+n+1);
    //    for (int i = 1; i <= n; i++) {
    //        cout<< a[i].val<< " ";
    //    }
    //    cout<< endl;
       for (int i = 2; i <= n; i++) {
           for (int j = 1; j <= n; j++) {
               if (a[j].place%i != 0) {
                   cout<< a[j].val;
                   if (i == n) {
                       cout<< endl;
                   } else {
                       cout<< " ";
                   }
                   break;
               }
           }
       }
   }

   return 0;
}
