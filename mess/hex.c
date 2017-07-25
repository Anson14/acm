#include<iostream>
#include<fstream>
using  namespace std;

#define MAX 100
#define MAXCOST 0x7fffffff

double graph[MAX][MAX];

double prim(double graph[][MAX], int n)
{
	double lowcost[MAX];
	int mst[MAX];
	int i, j, minid;
	double min, sum = 0;
	for (i = 2; i <= n; i++)
	{
		lowcost[i] = graph[1][i];
		mst[i] = 1;
	}
	mst[1] = 0;
	for (i = 2; i <= n; i++)
	{
		min = MAXCOST;
		minid = 0;
		//找到下一个节点的最小权
		for (j = 2; j <= n; j++)
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;
		sum += min;
		lowcost[minid] = 0;
		//更新lowcost 与 mst数组
		for (j = 2; j <= n; j++)
		{
			if (graph[minid][j] < lowcost[j])
			{
				lowcost[j] = graph[minid][j];
				mst[j] = minid;
			}
		}
	}
	return sum;
}

int main()
{
	int i, j, k, m, n;
	double x, y, cost;
	ifstream in("input.txt");
	in >> m >> n;//m=顶点的个数，n=边的个数
	//初始化图G
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}
	//构建图G
	for (k = 1; k <= n; k++)
	{
		in >> i >> j >> cost;
		graph[i][j] = cost;
		graph[j][i] = cost;
	}
	//求解最小生成树
	cost = prim(graph, m);
	//输出最小权值和
	cout << "最小权值和=" << cost << endl;

	return 0;
}