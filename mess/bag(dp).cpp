#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
#define MAX 102
using namespace std;

int n, W;
int w[MAX], v[MAX];

int rec(int i, int j) {
	int res;
	if (i == n) {
		res = 0;
	} else if (j < w[i]) {
		res = rec(i+1, j);
	} else {
		res  = max(rec(i+1, j), rec(i+1, j - w[i]) + v[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin>> n) {
		for (int i = 0; i < n; i++) {
			cin>> w[i]>> v[i];
		}
		cin>> W;
		cout<< rec(0,W)<< endl;
	}

	return 0;
}
