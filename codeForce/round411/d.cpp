/*************************************************************************
	> File Name: d.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 04 May 2017 11:34:33 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

string a;
long ans = 0;

int main() {
	ios::sync_with_stdio(false);
    while(cin>> a) {
        ans  = 0;
        bool flag = true;
        int b = 0;
        for (int i = a.length()-1; i >= 0; i--) {
            if (a[i] == 'a') {
                ans = (ans+b)%1000000007;
                b = (2*b)%1000000007;
            } else
                b++;
        }
        long k = ans%(1000000007);
        cout<< k<< endl;
    }

    return 0;
}
