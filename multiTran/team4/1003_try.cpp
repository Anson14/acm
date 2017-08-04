#include <bits/stdc++.h>
#define LL long long
#define N 100000

const int c = 998244353;

LL mark[N+1] = {0};
LL ans, l, r;
int n;

LL PowerMod(LL a, LL b)
{
    LL ans = 1;
    a = a % c;
    while(b>0) {
        if(b % 2 == 1)
        ans = (ans * a)% c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}

void InitPrimeTable()
{

    LL i, j, k;

    for (i = 2; i-N-1; mark[i] = i + 1, i++);
    for (i = 2; i-N-1; mark[k] = N + 1, i = mark[i])
    for (k = i, j = mark[i]; j-N-1; j = mark[j])
    if (j%i) mark[k] = j, k = j;

}

LL getIt(LL n) {
    LL result;
    for (int i = 2; i<N+1 && n >= i; i = mark[i])
    {
        int d = 0;
        while (n%i==0) ++d,n/=i;
        result *= d+1;
    }
    if (n != 1) result *= 2;
    return result;
}



int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    InitPrimeTable();
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%lld %lld %d",&l, &r, &n);
        for (LL i =l; i <= r; i++) {
            ans += getIt(PowerMod(i,n));
            if (ans > c) {
                ans %= c;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
