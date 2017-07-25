/*************************************************************************
	> File Name: c_1.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Sun 09 Apr 2017 09:10:19 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

#define MAX 1000005
int a[MAX];

int main() {
	ios::sync_with_stdio(false);
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int test;
    cin>> test;
    for (int t = 1; t <= test; t++) {
        clr(a);

        int n, k, ans;
        cin>> n>> k;
        a[0] = 1;
        a[n+1] = 1;
        int max = 0, l = 0, r = n+1,lp = 0 , rp = 0, pre = 0;
        for (int i = 0; i < k; i++) {
            ans = (l+r)/2;
            a[ans] = 1;
            if (((abs(l - lp) >= r -ans) && (l-lp >= ans - l)) ||( (abs(r-rp) > r-ans) && (abs(r-rp) > ans - l))) {

            }
            if (ans - l >= r - ans) {
                r = ans;
                rp = r;
            } else {
                l = ans;
                lp = l
            }
        }
        int ll = 0, rr = 0;
        for (int i = ans+1; i <= n+1; i++) {
            if (a[i] == 1) {
                rr = i - ans -1;
                break;
            }
        }
        for (int i = ans-1; i >= 0; i--) {
            if (a[i] == 1) {
                ll = ans - i -1;
                break;
            }
        }
        cout<< "Case #"<< t<< ": ";
        if (ll > rr)
            cout<< ll <<" "<< rr<< endl;
        else 
            cout<< rr<< " "<< ll<< endl;

    }

	return 0;
}
