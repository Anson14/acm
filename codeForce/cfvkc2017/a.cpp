/*************************************************************************
	> File Name: a.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 05 Apr 2017 11:36:45 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int n, x, y, adu = 0, pup = 0, p, an;

int main() {
	ios::sync_with_stdio(false);
    while (cin>> n) {
        cin>> x>> y;
        for (int i = 0; i < n; i++)  {
            cin>> p;
            if (p) {
                adu++;
            } else {
                pup++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (y*(i-1)*(i-1) < x) {
                an = i;
                break;
            }
        }
        int k = an - 1;
        int answer = 0;
        for (int i = 0; i < adu; i++) {
            adu--;
            pup -= k;
            if (!pup) {
                break;
            } else {
                answer++;
            }
        }
        int yu = adu%(an);
        answer += adu/(an);
        int val = answer*(x+y*k*k) + x + y*(yu-1)*(yu-1);
        cout<< val<< endl;

    }
    return 0;
}
