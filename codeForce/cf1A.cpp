#include <iostream>
#include <cstdio>
#include<cstring>
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int main()
{
	long int m, n;
	while (scanf("%ld %ld", &m, &n) != EOF) {
		long int a;
		scanf ("%ld", &a);
		long int sum = 0;
		long int answer = 0;
		while (sum<m) {
			sum += a;
			answer++;
		}
		sum = a;
		long answer2 = 1;
		while (sum < n) {
			sum += a;
			answer2++;
		}

		printf("%ld\n", answer*answer2);
		
	}

	return 0;
}