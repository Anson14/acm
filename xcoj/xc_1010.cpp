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

#define MAX 100

using namespace std;

int n, a[MAX];

int main() {
	ios::sync_with_stdio(false);
	while (cin>> n) {
		fill (a, a+MAX, -1);
		while (n--) {
			cin>> a[n];
			sort(a, a+n);
		}
	}

	return 0;
}