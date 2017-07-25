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

int main() {
	ios::sync_with_stdio(false);
	while (cin>> n) {
		if (n % 3 == 0) {
			cout<< "Cici"<< endl;
		} else {
			cout<< "Kiki"<< endl;
		}
	}

	return 0;
}