#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
long long B[11000];
int n, m;
void solve() {
    //scanf("%d%d", &n, &m);
    cin>> n>> m;
    assert(1 <= n && n <= 50 && 1 <= m && m <= 10000);
    for (int i = 0; i <= m; i++)// scanf("%lld", &B[i]);
        cin>> B[i];
    for (; n; n--) {
        int where = 0;
        for (int i = 1; i <= m; i++) if (B[i]) {
                where = i;
                break;
            }
        //printf("%d", where);
        cout<< where;
        if (n == 1) //printf("\n");
            cout<< endl;
        else //printf(" ");
            cout<< " ";
        for (int i = where; i <= m; i++) B[i] -= B[i - where];
    }
    assert(B[0] == 1);
    for (int i = 1; i <= m; i++) assert(B[i] == 0);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    //freopen("../in.txt", "r", stdin);
//	freopen("data.out","w",stdout);
    int t;
    //scanf("%d", &t);
    cin>> t;
    assert(1 <= t && t <= 70);
    for (; t; t--) solve();
    return 0;
}
