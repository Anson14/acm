#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>

#define MAX 2002

using namespace std;

int n;
char s[MAX];

void solve() {
    int a = 0, b = n - 1;
    int count = 0;
    while (a <= b) {
        bool left = false;
        for (int i = 0; a + i <= b; i++) {
            if (s[a + i] < s[b - i]) {
                left = true;
                break;
            } else if (s[a + i] > s[b - i]) {
                left = false;
                break;
            }
        }
        /*类似于这种的要求要在前面添加一位以及在后面添加一位，
        可以直接使用putchar(), 感觉很方便。
        */
        if (left) {
            putchar(s[a++]);
            count++;
        } else {
            putchar(s[b--]);
            count++;
        }
        if (count == 80) {
            putchar('\n');
            count = 0;
        }
    }
    putchar('\n');
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        int m = n;
        while (m--) {
            cin >> s[m];
        }
        solve();
        memset(s, 0, MAX);
    }

    return 0;
}