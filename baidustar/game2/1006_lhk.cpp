#include<bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
#define clr_1(x) memset(x,-1,sizeof(x)))
#define LL long long
#define mod 1000000007
using namespace std;
struct qj
{
    LL l,r;
}block[200010],ablock[200010];
bool cmp(qj a,qj b)
{
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
LL max(LL a,LL b)
{
    return a>b?a:b;
}
int main()
{
	freopen("in.txt", "r", stdin);
    int T;
    int n,head,tail,cnt;
    LL maxnday,sm,m;
    while(scanf("%d%I64d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d%I64d",&block[i].l,&block[i].r);
        }
        sort(block+1,block+n+1,cmp);
        cnt=0;
        block[0]=(qj){-1,-1};
//        for(int i=1;i<=n;i++)
//          cout<<block[i].l<<" "<<block[i].r<<endl;
//        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            block[i].r=max(block[i-1].r,block[i].r);
            if(block[i].l-block[i-1].r>1)
            {
                ablock[++cnt]=(qj){block[i-1].r+1,block[i].l-1};
            }
        }
//        for(int i=1;i<=cnt;i++)
//          cout<<ablock[i].l<<" "<<ablock[i].r<<endl;
//        cout<<endl;
        ablock[0]=(qj){-1,-1};
        ablock[cnt+1]=(qj){block[n].r+1,block[n].r+1};
        n=0;
        cnt++;
        for(int i=1;i<=cnt;i++)
        {
            if(ablock[i].l-ablock[i-1].r>1)
            {
                block[++n]=(qj){ablock[i-1].r+1,ablock[i].l-1};
            }
        }
//        for(int i=1;i<=n;i++)
//          cout<<block[i].l<<" "<<block[i].r<<endl;
//        cout<<endl;
        sm=0;
        head=1;
        tail=1;
        maxnday=0;
        while(head<n)
        {
            while(tail<n && sm+block[tail+1].l-block[tail].r-1<=m )
            {
                tail++;
                sm+=block[tail].l-block[tail-1].r-1;
            }
            maxnday=max(maxnday,block[tail].r-block[head].l+1+m-sm);
            sm-=(block[head+1].l-block[head].r-1);
            head++;
        }
        maxnday=max(maxnday,block[n].r-block[n].l+1+m);
        printf("%I64d\n",maxnday);

    }
}
/*
10 1000000000
1 100
2 200
3 300
4 400
5 200
520 600
601 700
701 800
801 900
901 10000
*/
