#include <iostream>
#include <cstdio>
#include <algorithm>
#include<string>
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

#define MAX 100
#define MAXCOST 0x7fffffff

int dijstra(int graph[][MAX], int n);

int graph[MAX][MAX];

int main()
{
	int i, j, k, m, n;
	int x, y, cost;
	cin >> m >> n;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			graph[i][j] = MAXCOST;
		}
	}

	for (k = 1; k <= n; k++) {
		cin >> i >> j >> cost;
		graph[i][j] = cost;
		graph[j][i] = cost;
	}

	return 0;
}

int dijstra(int graph[][MAX], int n)
{
	int lowcost[MAX];
	int minid, min;
	int mst[MAX];
	int sum = 0;
	for (int i = 2; i <= n; i++) {
		lowcost[i] = graph[1][i];
		mst[i] = 1;
	}

	mst[1] = 0;

	for (int i = 2; i <= n; i++) {
		min = MAXCOST;
		minid = 0;
		for (int j = 2; j <= n; j++) {
			if (lowcost[j] < min && lowcost[j] != 0) {
				min = lowcost[j];
				minid = j;
			}
		}
		cout << "v" << minid[j] << "v" << minid << " = " << min << endl;
		sum += min;
		lowcost[minid] = 0;

	}

}