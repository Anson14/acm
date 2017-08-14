#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define inf 0x3f3f3f3f
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
#define per(i,n,x) for(int i=n;i>=x;i--)
using namespace std;
typedef pair<int,int>P;
const int MAXN=100010;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
vector<int> mp[550];
bool flag;
int dfs(int u)
{
	int cnt = 0;
	for(int i = 0; i < mp[u].size(); i++)
	{
		cnt += dfs(mp[u][i]);
		if(cnt >= 2) flag = 1;
	}
	if(mp[u].size() == 0) return 1;
	return 0;
}
int main()
{
	freopen("in.txt", "r", stdin);
	int T, u;
	cin >> T;
	while(T--)
	{
		flag = 0;
		int n, k;
		cin >> n >> k;
		for(int i = 2; i <= n; i++)
		{
			scanf("%d", &u);
			mp[u].pb(i);
		}
		dfs(1);
		if(!(n % 2 == 0 && k >= n / 2 - 1))
		flag = 1;
		if(flag)
		cout << "Alice\n";
		else
		cout << "Bob\n";
		for(int i = 1; i <= n; i++)
		mp[i].clear();
	}
 	return 0;
}