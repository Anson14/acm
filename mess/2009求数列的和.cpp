#include <iostream>
#include <cstdio>
#include<cstring>
#include <cmath>

#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int main() {
	int n;
	int m;
	while(scanf("%d %d", &n, &m) != EOF) {
		double sum = 0;
		double s = n;
		while (m--) {
			sum += s;
			s = pow(s, 0.5);
		}
		printf("%.2f\n", sum);
	}
}