#include<bits/stdc++.h>
#define MAXN 100050
#define LL long long

using namespace std;
int n,m;
LL dp[MAXN][11];//把防御值为j的怪物，生命值打掉i需要消耗的最少的水晶数。
LL num[MAXN][11];//num[i][j]生命值为i，防御为j的怪物个数
int consume[MAXN],hurt[MAXN];
LL ans=0;
int best[MAXN];
struct SKILL
{
    int hurt;
    int consume;
}a[MAXN];

int main()
{
    freopen("in.txt", "r", stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        memset(best,0,sizeof(best));

        int hurtma=0,defma=0,hpma=0;int lx,ly;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&lx,&ly);
            num[lx][ly]++;
            if(defma<ly)defma=ly;
            if(hpma<lx)hpma=lx;
        }
        int numl=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&lx,&ly);
            if(best[ly]!=0&&best[ly]<=lx)continue;
            best[ly]=lx;
            a[numl].consume=lx;a[numl].hurt=ly;
            if(a[numl].hurt>hurtma)
            {
                hurtma=a[numl].hurt;
            }
            numl++;
        }
        m=numl;
        if(hurtma<=defma)
        {
            printf("-1\n");
            continue;
        }
        //sort(a,a+m,my_cmp);
        for(int k_def=0;k_def<=10;k_def++)//枚举所有防御力可能
        {
            if(k_def!=0)
            for(int i=0;i<m;i++)
            {
                a[i].hurt--;
            }
            for(int i=1;i<=hpma;i++)
            {
                long long t=-1;
                for(int j=0;j<m;j++)
                {
                    if(a[j].hurt<=0)continue;
                    if(i-a[j].hurt<=0)
                    {
                        if(t==-1||t>a[j].consume)
                        {
                            t=a[j].consume;
                        }
                        continue;
                    }
                    if(t==-1||t>dp[i-a[j].hurt][k_def]+a[j].consume)
                    {
                        t=dp[i-a[j].hurt][k_def]+a[j].consume;
                    }
                }
                dp[i][k_def]=t;
            }
        }
        for(int i=0;i<=hpma;i++) {
            for(int j=0;j<=10;j++) {
                ans+=(dp[i][j]*num[i][j]);
            }
        }
        printf("%I64d\n",ans);
    }

}
