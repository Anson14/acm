#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<iostream>  
#include<string>  
#include<vector>  
#include<stack>  
#include<bitset>  
#include<cstdlib>  
#include<cmath>  
#include<set>  
#include<list>  
#include<deque>  
#include<map>  
#include<queue>  
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 100;  
int T,n,m;  
int year,mouth,day;  
  
int solve(int yy,int mm,int dd)  
{  
    int m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};  
    if(mm==0||mm>12||dd==0||dd>31)  
    {  
        return -1;  
    }  
    if(!((yy%4==0)||yy%400==0))  
        m[2]=28;  
    else  
        m[2]=29;  
    if(dd>m[mouth])  
    {  
        return -1;  
    }  
    if(mm<3)  
    {  
        yy--;  
        mm+=12;  
    }  
    int c=yy/100;  
    int y=yy%100;  
    return (((c/4-2*c+y+y/4+13*(mm+1)/5+dd-1)%7+7)%7);  
}  
  
  
int main()  
{  
	freopen("in.txt", "r", stdin);
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d-%d-%d",&year,&mouth,&day);  
        int ans=solve(year,mouth,day);  
        for(int i=1;;i++)  
        {  
           if(solve(year+i,mouth,day)==ans)  
           {  
               printf("%d\n",year+i);  
               break;  
           }  
        }  
    }  
    return 0;  
}