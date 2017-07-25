#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int main() {
	int n;
	char m[11];
	scanf ("%d", &n) ;
	while (scanf("%s", &m) != EOF) {
		int sum = 0;
		// int b[11] = {1, 9, 45, };
		int a[11];
		fill(a, a+11, -1);
		int j = 0;
		for (int i = 0 ; i < 11; i ++){
			if (m[i] >= '0' && m[i] <= '9') {
				a[j] = m[i]-48;
				j++;
			}
		}
		int aaaa = 0;
		for (int i = 0; i < 10; i ++) {
			for (int j =  0; j < i; j++)
				aaaa += i;
		}
		printf("%d\n", aaaa);
		for (int i = 0; i < j; i++) {
			int key = a[i] *(j-1);

		}
	}

	return 0;
}