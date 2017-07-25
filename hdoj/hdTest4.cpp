#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int main() {
	int t;
	cin>> t;
	while (t--) {
		int n, m;
		int a = 0, b = 0, c = 0, d = 0;
		cin>> n>>  m;
			while (n--) {
				string xxx;
				cin>> xxx;
				if (xxx == "Fire") {
					a++;
				} 
				if (xxx == "Ice")
					b++;
				if (xxx == "Dog") {
					c++;
				}
				if (xxx == "Evolved") {
					d++;
				}
			}
			int sum = 10;
			int max = 0;
			if (a == 0 && b == 0)
			{
				cout<< "No"<< endl;
			}
			if (m > 16) {
				cout<< "No"<< endl;
			}
			if (a>=2 && b>=1 || a>=1 && b>=3  || a>= 1 && )
		}
	return 0;
}