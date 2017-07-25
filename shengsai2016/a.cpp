/*************************************************************************
	> File Name: a.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 17 May 2017 10:27:01 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int a, b, c, d, t;

int main() {
	ios::sync_with_stdio(false);
    cin>> t;
    while (t--) {
        cin>> a>> b>> c>> d;
        cout<< abs(b*a-c*d)<< endl;

    }


	return 0;
}
