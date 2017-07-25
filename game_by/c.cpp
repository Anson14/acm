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

using namespace std;

long long n, a[45];

int main() {
    ios::sync_with_stdio(false);

    a[0] = 2, a[1] = 3;
    for (int i = 2; i < 45; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    while(cin >> n) {
        if (n ==  0) {
            break;
        }
        bool k = false;
        int i = 0;
        for (i = 0; i < 45; i++) {
            if (n == a[i]) {
                k = true;
                break;
            }
        }
        if (!k) {
            cout << "First win" << endl;
        } else {
            cout << "Second win" << endl;
        }
    }

    return 0;
}