#include    <stdio.h>

#define N 1000

int    mark[N+1] = {0};

void InitPrimeTable()
{

    int    i, j, k;

    for (i = 2; i-N-1; mark[i] = i + 1, i++);
    for (i = 2; i-N-1; mark[k] = N + 1, i = mark[i])
    for (k = i, j = mark[i]; j-N-1; j = mark[j])
    if (j%i) mark[k] = j, k = j;

}


int gcd(int a, int b)
{return b ? gcd(b, a%b) : a;}
int main()
{
    int n;
    InitPrimeTable();
    scanf("%d", &n);
    while (n--)
    {
        int a, b, i, curr = 0, result = 1;
        int n;
        scanf("%d", &n);
        //for (int num = 1; num < 100; num++) {
            //n = n*n*n;
            printf("%d", n);
            for (i = 2; i<N+1 && n >= i; i = mark[i])
            {
                int c = 0;
                while (n%i==0) ++c,n/=i;
                result *= c+1;
            }
            if (n != 1) result *= 2;
            printf(":   %d\n", result);
        }
    //}
    return 0;
}
