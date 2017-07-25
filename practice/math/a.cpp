/*************************************************************************
	> File Name: a.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Sun 23 Apr 2017 08:24:24 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    int a, b;
    while (cin>> a>> b && a != 0 || b != 0) {
        a = a*100;
        bool flag = false;;
        for (int c = 0; c < 10; c++) {
            if ((a+c) % b == 0) {
                if (flag) {
                    cout<< " ";
                }
                flag = true;
                cout<< "0"<< c;
            }
        }
        for (int c = 10; c < 100; c++){
            if ((a+c) % b == 0) {
                if (flag) {
                    cout<< " ";
                } 
                flag = true;
                cout<< c;
            }
        }
        cout<< endl;
    }
	return 0;
}
