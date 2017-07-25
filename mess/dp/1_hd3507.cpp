/*************************************************************************
	> File Name: 1_hd3507.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Mon 27 Mar 2017 01:47:18 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int dp[500005];
int q[500005];
int sum[500005];
int head, tail, n, m;

int getdp(int i, int j) {
    return  dp[j] + m +(sum[i]-sum[j])*(sum[i]-sum[j]);
}

int getMole(int j, int k) {
    return dp[j]+sum[j]*sum[j] - dp[k]-sum[k]*sum[k];
}

int getDeno(int j, int k) {
    return 2*(sum[j]-sum[k]);
}

int main() {
	ios::sync_with_stdio(false);
    //freopen("in.txt","r", stdin);
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &sum[i]);
        }
        sum[0] = dp[0] = 0;
        //求前缀和
        for (int i = 1; i <= n; i++) {
            sum[i] += sum[i-1];
        }
        //初始化队列
        head = tail = 0;
//        q[tail] = 0;
//      tail ++;
        q[tail++] = 0;
        for (int i = 1; i <= n; i++) {
            //找到当前点i可以放入的位置
            while (head+1 < tail && getMole(q[head+1], q[head]) <= sum[i] * getDeno(q[head+1], q[head])) {
                head++;
            }
            //获取消费
            dp[i] = getdp(i, q[head]);
            //xi / xj <= yi / yj
            //维护凸包，把队列中可以去掉的点去掉
            while (head+1 < tail && getMole(i, q[tail-1])*getDeno(q[tail-1], q[tail-2]) <= getMole(q[tail-1], q[tail-2])*getDeno(i, q[tail-1])){
                tail--;
            }
            //入队
            q[tail++] = i;
        }
        printf("%d\n", dp[n]);
    }

	return 0;
}
