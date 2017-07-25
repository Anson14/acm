/*************************************************************************
	> File Name: c.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Sat 08 Apr 2017 10:36:34 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

#define MAX 1005

int a[MAX];
int b[MAX];

int main() {
    ios::sync_with_stdio(false);
    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    int test;
    cin>> test;
    for (int t = 1; t <= test; t++) {
        clr(a);
        clr(b);
        int k = 0, n = 0;
        cin>> n>> k;
        cout<< "Case #"<< t<< ": ";
        if (n == k) {
            cout<< "0 0"<< endl;
        } else {
            a[0] = 0; a[1] = n+1;
            int ans = 0, l = 0, r = n+1;
            if (n % 2 == 0) {
                ans = (n)/2;
            } else {
                ans = (n+1)/2;
            }
            b[0] = ans - 0;
            b[1] = r-ans;
            a[2] = ans;
            int cnt = 3;
            int cat = 2;
            for (int i = 1; i < k; i++) {
                //if (ans - l >= r - ans) {
                    //r = ans;
                //} else {
                    //l = ans;
                //}
                for (int p = 0; p < cat; p++) {
                    
                }
                ans = (l+r+1)/2;
                a[cnt++] = ans;
            }
            int ll = 0, rr = 0;
            sort(a, a+k+2);
            int j = 0;
            
            for (int i = 0; i < k+2; i++) {
                cout<< a[i]<< endl;
            }

            for (int i = 0; i < k+2; i++) {
                if (a[i] == ans) {
                    j = i;
                    break;
                }
            }
            ll = ans - a[j-1] - 1;
            rr = a[j+1] - ans - 1;
            if (ll > rr) {
                cout<<ll << " "<< rr;
            } else {
                cout<< rr<< " "<< ll;
            }
            cout<< endl;
        }
    }
return 0;
}
