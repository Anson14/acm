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

int n;
int l[11];
bool rrr[11];

bool judge (int x) {
	int len = 0;
	int b[10];

	while (x) {
		b[++len] = x % 10;
		if (!rrr[b[len]]) {
			return false;
		}
		x /= 10;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	while(cin>> n){
		int i = 0;
	    int m = n;
	    fill(rrr, rrr + 11, false);
		while (m--) {
			int x = 0;
			cin>> x;
			l[i++] = x;
	        rrr[x] = true;
		}
	    
		int all = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int q = 0; q < n; q++) {
					for (int w = 0; w < n; w++) {
						for (int e = 0; e < n; e++) {
							if (l[i] && l[w]){
								int qq = l[i] * 100 + l[j] * 10 + l[q];
								int ww = l[w] * 10 + l[e];
								int zz = qq * l[w];
								int xx = qq * l[e];
								int cc = qq * ww;
								if (judge(zz) && judge(xx) && judge(cc)) {
									if (zz >99 && zz < 1000 && xx > 99 && xx < 1000 && cc > 999 && cc < 10000) {
										all++;
									}
								}
							}
						}
					}
				}
			}
		}
		cout<< all<< endl;
	}
	return 0;
}
