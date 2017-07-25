#include <iostream>
#include <cstdio>
#include<cstring>

#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int main()
{
	int n;
	while (cin>> n) {
		if (n == 0) {
			break;
		} else {
			double a[n];
			int z = 0, x = 0, c = 0;
			for (int i = 0; i < n; i++) {
				cin>> a[i];
				if (a[i] < 0) {
					z++;
				} else if (a[i] > 0) {
					c++;
				} else {
					x++;
				}
			}
			cout<< z<< " "<< x<< " "<< c<< endl;

		}
	}
}