/*************************************************************************
> File Name: 1011.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月25日 星期二 13时00分16秒
************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
//#include <bits/stdc++.h>
#define LL long long
#define clr(x) memset(x,0,sizeof(x))
using namespace std;

int k = 0;
LL val;
LL a[26];
string s[100005];

int fun(char a) {
    return (int)(a-'a');
}


int main(){
	int n, ca = 0; LL k;
	while(~scanf("%d%lld", &n, &k)){
		if(k <= n) printf("Case #%d: %lld\n", ++ca, k);
		else{
			k -= n;
			LL t = k / (n - 1);
			k %= n - 1;
			if(!k) printf("Case #%d: %d\n", ++ca, t & 1 ? n - 1 : n);
			else printf("Case #%d: %lld\n", ++ca, k);
		}
	}
  return 0;
}
