/*************************************************************************
	> File Name: D.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-19 Sun 19:27:25 CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

bool digit[10];
int all[10];
int N;

int get(int *n, int len) {
	int x = 0;
	for (int i = len-1; i>=0; --i)
		x = x*10 + n[i];
	return x;
}

bool judgeResult(int x) { // 数字是否都存在
	while(x) {
		if(! digit[x % 10]) return false;
		x /= 10;
	}
	return true;
}

bool check(int *x, int *y) {
	int X = get(x, 3);
	if(X < 100 || X>999) return false;
	int Y = get(y, 2);
	if(Y < 10 || Y>99) return false;


	int R1 = X * y[0];
	if(R1 < 100 || R1 > 999 || !judgeResult(R1)) return false;
	int R2 = X * y[1];

	if(R2 < 100 || R2 > 999 || !judgeResult(R2)) return false;
	int R3 = R1 + R2 * 10;
	if(R3 < 1000 || R3 > 9999 || !judgeResult(R3)) return false;
	// printf("X=%d Y=%d\n", X, Y);
	return true;
}

int solve() {
	map<pair<int, int>, bool> hash;
	int x[3];
	int y[2];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				// printf("i=%d j=%d k=%d\n", i, j, k);
				x[0] = all[i];
				x[1] = all[j];
				x[2] = all[k];
				do {
					for (int a = 0;a < N; ++a) {
						for (int b = 0;b < N; ++b) {
							y[0] = all[a];
							y[1] = all[b];
							do {
								// printf("a=%d b=%d\n", a, b);
								if(check(x, y))
									hash[make_pair(get(x,3), get(y,2))] = true;

							} while(next_permutation(y, y+2));
						}
					}
				} while(next_permutation(x, x+3));

			}
		}
	}
	return hash.size();
}

int main(void) {
	// freopen("D.in", "r", stdin);

	while(scanf("%d", &N) == 1 && N) {
		memset(all, 0, sizeof(all));
		memset(digit, 0, sizeof(digit));

		for (int i = 0; i < N; ++i) {
			scanf("%d", &all[i]);
			digit[all[i]] = true;
		}

		printf("%d\n", solve());
	}

	return 0;
}