/*************************************************************************
	> File Name: fhy_a.cpp
	> Author: Anson
	> Mail: 354830997@qq.com
	> Created Time: Sat 08 Apr 2017 03:25:41 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("A-large.in.txt", "r", stdin);  
    freopen("out.txt", "w", stdout);
    int t; 
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int k; 
        cin>>s;
        scanf("%d",&k);
        int len1= s.length();
        string str="";
        for(int i=0;i<len1;i++)
        {
            if(s[i]=='-')
            str+='1';
            else
            str+='0';
        }
        int len=str.length();
        queue<int> Q;
        bool flag = true;
        int ans = 0, top = 0;
        for(int i = 0; i < len; i++)
        {
            if(!Q.empty() && Q.front() < i)
                Q.pop();
            int op = str[i] - '0' + Q.size();
            if(op & 1) //此处为与操作符 不要与 && 弄混淆
            {
                ans++;
                if(i + k - 1 >= len)
                {
                    flag = false;
                    break;
                }
                Q.push(i+k-1);
            }
        }
        if(flag)
        printf("Case #%d: %d\n",cas,ans);
        else
        printf("Case #%d: IMPOSSIBLE\n",cas);
    }

    return 0;
}
