/*************************************************************************
    > File Name: b.cpp
  > Author: Anson
  > Mail: 354830997@qq.com
  > Created Time: 2017年06月25日 星期日 15时59分51秒
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
#define MAXN 1005

int n;

void solve(string s) {
    for (int i = 2; i <= 16; i++) {
        string temp = "";
        for (int j = 1; j <= n; j++) {
            int p = j;
            while (p) {
                temp += (p % i) + '0';
                p /= i;
            }
        }
        cout << temp << endl;
        bool keep = false;
        for (int x = 0; x < temp.length(); x++) {
            if (temp[x] == s[0]) {
                keep = true;
                for (int z = 0; z < s.length(); z++) {
                    if (temp[x + z] != s[z]) {
                        keep = false;
                        break;
                    }
                }
                if (keep) {
                    cout << "yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "no" <<  endl;
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    while (cin >> n) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}
