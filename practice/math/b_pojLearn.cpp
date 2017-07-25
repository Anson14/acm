#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
void div(int n)
{
    int a[1000];
    int k=0;
    memset(a,0,sizeof(a));
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            a[k++]=i;
            while(n%i==0)
            {
                ++a[k];
                n/=i;
            }
            ++k;
        }
    }
    if(n>1)
    {
        a[k++]=n;
        ++a[k++];
    }
    for(int i=k-1;i>=1;i-=2)
        printf("%d %d%c",a[i-1],a[i],((i==1)?'\n':' '));
}
int Pow(int a,int x)
{
    int ans =1;
    while(x)
    {
        if(x & 1) ans=ans*a;
        a*=a;
        x>>=1;
    }
    return ans;
}
int main()
{
    char c;
    int a,b,n;
    while((c=getchar())!='0')
    {
        a = b= 0;
        n =1;
        a=c-'0';
        while(c=getchar())
        {
            if(isdigit(c))
            {
                a=a*10+c-'0';
                while((c=getchar()))
                    if(c==' ') break;
                    else a=a*10+c-'0';
            }
            while((c=getchar()))
                if(isdigit(c)) b=b*10+c-'0';
                else break;
            n*=Pow(a,b);
            a = b = 0;
            if(c=='\n') break;
        }
        printf("%d   ",n);
        div(n-1);
    }
}
