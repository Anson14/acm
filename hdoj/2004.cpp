/*************************************************************************
	> File Name: 2004.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Wed 24 May 2017 10:36:59 AM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
    while (~scanf("%d", &n)) {
        if (n > 100 || n < 0) {
            printf("Score is error!\n");
            continue;
        }
        char g = 'A';
        if (n >= 90) {
            g = 'A';
        } else if (n >= 80) 
            g = 'B';
        else if (n >= 70)
            g = 'C';
        else if (n >= 60) 
            g = 'D';
        else 
            g = 'E';

        printf("%c\n", g);
    }

	return 0;
}
