/*************************************************************************
	> File Name: a.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 11 May 2017 11:38:53 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int n,t,k,d;

int main() {
	ios::sync_with_stdio(false);
    while (cin>> n>> t>> k>> d) {
        int a = 0, b = 0;
        a = n/k;
        a *= t;
        if (n % k != 0) {
            a+=t;
        }

        n -= k*(d/t);
        if (n < 0) {
            n = 0;
        }
        b = n/(2*k);
        b *= t;
        if (n % (2*k) != 0) {
            b += t;;
        }
        b += d;
        //cout<< a<< " "<< b<< " ";
        if (a > b) {
            cout<< "YES"<< endl;
        } else {
            cout<< "NO"<< endl;
        }
    }

	return 0;
}
