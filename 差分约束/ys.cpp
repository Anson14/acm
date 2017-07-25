/*************************************************************************
	> File Name: ys.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Fri 17 Mar 2017 09:09:44 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define INF 100000000 
#define MAXN 50100

using namespace std;

struct edge{
    int next;
    int to;
    int w;
} e[50010];
int head[50010];
int dis[50010];
bool in[50010];
queue<int> q;
int n, maxm, mini, cnt = 0;

bool spfa(int s) {
    for (int i = 0; i < maxm; i++) {
        dis[i] = INF;
        in[i] = 0;
    }
    dis[s] = 0; in[s] = true;
    q.push(s);
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        in[tmp] = false;
        for (int j = head[tmp]; j != INF; j = e[j].next) {
            if(dis[tmp] + e[j].w < dis[e[j].to]) {
                dis[e[j].to] = dis[tmp] + e[j].w;
                if(!in[e[j].to]) {
                    in[e[j].to] = true;
                    q.push(e[j].to);
                }
            }
        }
    }
    return false;
}

void addEdge(int s, int t, int v) {
    e[cnt].w = v;
    e[cnt].to = t;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

int main() {
	ios::sync_with_stdio(false);
    while (scanf("%d", &n) != EOF) {
        mini = INF;
        maxm = 0;
        for (int i = 0; i < n; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            mini = MIN(mini, a);
            maxm = MAX(maxm, b+1);
            addEdge(b+1, a, -c);
        }
        for (int i = mini; i < maxm; i++) {
            addEdge(i, i+1, 1);
            addEdge(i+1, i, 0);
        }
        spfa(maxm);
        //for (int i = 0; i < 15; i++)
        printf("%d\n", -dis[mini]);
    }
	return 0;
}
