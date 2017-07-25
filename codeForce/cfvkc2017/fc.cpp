#include<cstdio>
#include<iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include<cstring>
#define inf 0x3f3f3f3f

using namespace std;

int hl[10]={7,2,5,5,4,5,6,3,7,6};
int out[10]={0,0,1,7,4,5,9,8,0,0};
int dp1[100010];
int pre[100010];
int bit[100010];

int main()
{
	memset(dp1,0,sizeof(dp1));
	memset(bit,0,sizeof(bit));
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		for(int j=9;j>=0;j--)
		{
			if(i-hl[j]>=0 && (j!=0 || (bit[i-hl[j]]>0 && j==0)))
				if(bit[i-hl[j]]>bit[i])
				{
					bit[i]=bit[i-hl[j]];
					pre[i]=i-hl[j];
				}
		}
		bit[i]++;
	}
	for(int i=n;pre[i]!=i;i=pre[i])
	{
		printf("%d",out[i-pre[i]]);
	}
	printf("\n");
	return 0;
}
