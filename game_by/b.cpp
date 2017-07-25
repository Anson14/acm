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

int k, m, n;
bool win[10002];
int main() {
    getchar();
    while (scanf("%d%d", &m, &n) != EOF) {
        win[0] = false;
        for (int i = 1; i <= n; i++) {
            win[i] = false;
            win[i] |= m <= i && !win[i - m];
        }
	    if (!win[n]) {
	    	printf("Rabbit\n");
	    } else {
	    	printf("Grass\n");
	    }
    }

    return 0;
}