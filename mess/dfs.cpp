#include <bits/stdc++.h>

#define MAX 100

using namespace std;

int a[MAX];
int n, k;

bool dfs(int i, int sum) {
	if (i == n) {
		return sum == k;
	}
	if (dfs(i+1, sum)) {
		return true;
	}
	if (dfs(i+1, sum+a[i])) {
		return true;
	}

	return false;
}

int main()
{
	while (cin>> n){
		for (int i = 0; i < n; i++) {
			cin>> a[i];
		}
		cin>> k;
		if(dfs(0, 0)){
			cout<< "yes"<< endl;
		} else {
			cout<< "no"<< endl;
		}
	}
}

