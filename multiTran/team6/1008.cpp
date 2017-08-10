/*************************************************************************
> Author: AnsonTang
> Mail: 354830997@qq.com
> Created Time: 2017 Thu Aug 10 2017 13:17:12
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

int t, m, len;
char s[20005];

int qabs(char a, char b) {
    if (a>b) {
        return (int)(a-b);
    } else {
        return (int)(b-a);
    }
}

void solve() {
    int ans = 0;
    for (int x = 1; x <= len-1; x++) {
        int k = 0;
        int h1 = 0, h2 = len - x;
        int t1 = 0, t2 = h2;
        int sum = 0;
        while (k++<len/2 && t1<t2) {
            // cout<< "x: "<< x<< " "<< sum<< " "<<h1<< " "<< t1<< " "<< h2<< " "<< t2<< endl;
            while (t1<t2) {
                sum +=  qabs(s[t1],s[t2]);
                if (sum > m) {
                    sum -=  qabs(s[t1],s[t2]);
                    break;
                }
                if (t1 - h1+1 > ans) {
                    ans = t1-h1+1;
                }
                // cout<< sum<< " "<< t1<< " "<< t2<< endl;
                t1++,t2--;
            }
            // cout<< endl;
            sum -= qabs(s[h1],s[h2]);
            h1++;
            h2--;
        }
    }
    
    for (int x = 1; x <= len-1; x++) {
        int k = 0;
        int h1 = x, h2 = len - 1;
        int t1 = x, t2 = h2;
        int sum = 0;
        while (k++<len/2 && t1<t2) {
            // cout<< "x: "<< x<< " "<< sum<< " "<<h1<< " "<< t1<< " "<< h2<< " "<< t2<< endl;
            while (t1<t2) {
                sum +=  qabs(s[t1],s[t2]);
                if (sum > m) {
                    sum -=  qabs(s[t1],s[t2]);
                    break;
                }
                if (t1 - h1+1 > ans) {
                    ans = t1-h1+1;
                }
                // cout<< sum<< " "<< t1<< " "<< t2<< endl;
                t1++,t2--;
            }
            // cout<< endl;
            sum -= qabs(s[h1],s[h2]);
            h1++;
            h2--;
        }
    }

    cout<< ans<< endl;
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    cin>> t;
    while(t--) {
        cin>> m;
        cin>> s;
        len = strlen(s);
        solve();
    }

    return 0;
}