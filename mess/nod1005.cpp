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
using namespace std;

#define MAX 10002

string a, b;
int c[10002];

int change(char a) {
	return (int) a - 48;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin>> a>> b) {
		int u = 10001;
		if ((a[0] != '-' && b[0] != '-') || (a[0] == '-' && b[0] == '-')){
			int flag = 0;
			if(a.length()<b.length()) {
				swap(a,b);
			}
			int i = a.length()-1;
			int j = b.length()-1;
			while (i >= 0 && j >= 0){			
				c[u] =  (change(a[i]) + change(b[j]) )%10 + flag;
				flag = (change(a[i]) + change(b[j]))/10;
				if (c[u] > 9) {
					c[u] = c[u]-10;
					flag ++;
				}
				cout<< flag<< endl;
				cout<< "u "<< u<< " "<< c[u]<< endl;
				u--;
				i--;j--;
			if (a[0] = '-' && b [0] == '-' && j == 0)
				break;
			}
			cout<< i<< " "<< j<< endl;
			while (i!= -1) {
				c[u] =  change(a[i])%10 + flag;
				cout<< "u "<< u<< " "<< c[u]<< endl;

				flag = 0;
				i--;
				u--;
				if (a[0] = '-' && b [0] == '-' && i == 0)
					break;
			}
			if (a[0] = '-' && b [0] == '-'){
				cout<< '-';
				for (u++; u < 10002; u++) {
					cout<< c[u];
				}
				cout<< endl;
			} 
		} else {
			if (a[0] == '-') {
				swap(a, b);
			}
			int flag = 0;
			int i = a.length()-1;
			int j = b.length()-1;
			while (i >= 0 && j >= 0){
				if (change(a[i]) - change(b[j]) > 0){
					c[u] =  (change(a[i]) - change(b[j]) ) - flag;
					flag = 1;
				} else {
					c[u] = (change(a[i]) - change(b[j]) + 10) - flag;
					flag = 0;
				}
				u--;i--;j--;
			}

			for (u++; u < 10002; u++) {
				cout<< c[u];
			}
			cout<< endl;
		}
	}

	return 0;
}
