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
#define clrmin(x) memset(x,-1,sizeof(x))
#define clrmax(x) memset(x,0x3f3f3f3f,sizeof(x))
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
int n, maxm, mini, cnt;

bool spfa(int s) {
    for (int i = 0; i < maxm; i++) {
        dis[i] = INF;
        in[i] = false;
    }
    dis[s] = 0; in[s] = true;
    q.push(s);
    int ttt = 0;
    while(!q.empty()) {
    	ttt++;
    	if (ttt == 36) {
    		return false;
    	}
        int tmp = q.front();
        q.pop();
        in[tmp] = false;
        // printf("%d\n", tmp);
        for (int j = head[tmp]; j != -1; j = e[j].next) {
        	// printf("%d  lll %d  llll %d\n", j, dis[tmp], e[j].to);
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
    return;
}

int main() {
	ios::sync_with_stdio(false);
    while (scanf("%d", &n) != EOF) {
    	clrmin(head);
        mini = INF;
        maxm = 0;
        cnt = 0;
        for (int i = 0; i < n; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            mini = MIN(mini, a);
            maxm = MAX(maxm, b+1);
            addEdge(a, b+1, c);
        }
        for (int i = mini; i < maxm; i++) {
            addEdge(i, i+1, 0);
            addEdge(i+1, i, -1);
        }
        spfa(mini);
        for (int i = mini; i < maxm; i++)
   	    	printf("%d   %d   %d    %d\n",i, head[i], e[i].to, e[i].next);
   	    printf("%d\n", dis[maxm]);
    }
	return 0;
}
