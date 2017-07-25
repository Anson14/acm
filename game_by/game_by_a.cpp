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

int a, b;

int main()  {
    while (scanf("%d%d", &a, &b) != EOF) {
        int k = abs(a - b);
        int n = (int)(k) * (1 + sqrt(5)) / 2;
        if (n == min(a,b)) {
        	printf("0\n");
        } else {
        	printf("1\n");   
        }
    }

    return 0;
}