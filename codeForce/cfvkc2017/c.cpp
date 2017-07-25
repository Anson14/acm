/*************************************************************************
	> File Name: c.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Thu 06 Apr 2017 12:23:28 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
    while (cin>> n) {
        if (n == 5) {
            cout<< "71"<< endl;
            continue;
        }
        else if (n == 2) {
            cout<< "1";
        } else if (n == 3) {
            cout<< "7";
        } else {
            if (n%2 != 0) {
                int k = n/2-1;
                cout<< "7";
                while (k--) {
                    cout<<"1";
                }
            }  else {
                int k = n/2;
                while (k--) {
                    cout<< "1";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
