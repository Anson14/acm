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

#define ll long long

#define MAX 50002

using namespace std;

int n, l[MAX];

void solve() {
	ll ans = 0;

	while (n > 1) {
		int mii1 = 0, mii2 = 1;
		if (l[mii1] > l[mii2]) {
			swap(mii1, mii2);
		}
		for (int i = 2; i < n; i++) {
			if (l[i] < l[mii1]) {
				mii2 = mii1;
				mii1 = i;
			} else if (l[i] < l[mii2]) {
				mii2 = i;
			}
		}

		int t = l[mii1] + l[mii2];
		ans += t;

		if (mii1 == n-1) {
			swap(mii1, mii2);
		}
		l[mii1] = t;
		l[mii2] = l[n-1];
		n--;
	}

	printf("%lld\n", ans);
}

int main() {
	// ios::sync_with_stdio(false);
	while (scanf("%d", &n) != EOF) {
		getchar();
		memset(l, 0, MAX);
		int i = 0;
		while (i < n) {
			scanf("%d", &l[i++]);
		}
		solve();
	}
	return 0;
}
