#include <iostream>
#include <cstdio>
#include<cstring>
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
int qu(int x);

struct node {
    int fa;
    int biao;
};
node a[100001];

int main()
{
    int n = 1, q;
    scanf ("%d %d", &n, &q);
     while (n){
		long long sum = 0;
        clr(a);
        a[1].biao = 1;
        a[1].fa=1;
        int x;
        char yyy;
        for (int i = 2; i <= n; i++){
            scanf ("%d", &a[i].fa);
        }
        for (int i = 0; i < q; i++){
        	getchar();
            scanf ("%c %d",&yyy,&x);
            if (yyy == 'M'){
                a[x].biao = 1;
            }
            if (yyy == 'Q'){
                sum += qu(x);
            }
        }
        printf("%ld\n", sum);
        scanf ("%d %d", &n, &q);
    }
    return 0;
}

int qu(int x){
    while (a[x].biao != 1){
        x = a[x].fa;
    }
    return x;
}