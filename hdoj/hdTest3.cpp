#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int main() {
	int t;
	scanf("%d", &t);
		int n  = 0, m = 0;
		while (scanf("%d%d", &n, &m)!= EOF){
		int sum = 0;
		int x = 0;
			if (n >= 3) {
				n = n-  m;
				x = m%3;
				sum += m/3;
			if (n <= 3) {
				if ()
				sum+= 2;

			}else if (n <= 6) {
				sum += 3;

			} else if (n <= 10) {
				sum+= 4;

			} else {
				sum+=(n/10) * 4;
				n %= 10;
				if (n <= 3) {
					sum+= 2;
				} else if (n <= 6) {
					sum += 3;
				} else {
					if (n == 7)
						sum+= 3;
					else {
						sum+= 4;
					}
				}

			}
		} else {
			if (n != m){
				sum += 2;
			} else {
				sum += 1;
			}

		}
		printf("%d\n", sum);
	}

	return 0;
}