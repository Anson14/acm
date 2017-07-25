#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int M = 1e2+5;
const int INF = 0x3f3f3f3f;
using namespace std;
int dp[M], a[M], p[M];

int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        int n;
        scanf("%d", &n);
        a[0] = 0;
        int w;
        for(int i = 1; i <= n; ++ i){
            scanf("%d%d", &w, p+i);
            a[i] = a[i-1]+w;
        }
        memset(dp, 0, sizeof(dp));
        int ans = INF;
        for(int i = 1; i <= n; ++ i){
            int Min = INF;
            for(int j = 0; j < i; ++ j){
                if(dp[j]+(a[i]-a[j]+10)*p[i] < Min){
                    Min = dp[j]+(a[i]-a[j]+10)*p[i];
                }
            }
            dp[i] = Min;
            //ans  = min(ans, dp[i]);
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}