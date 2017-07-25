/*************************************************************************
> File Name: 1273.cpp
> Author: Anson
> Mail: 354830997@qq.com
> Created Time: 2017年07月24日 星期一 16时32分48秒
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
#define MAXN 1005

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,b,c,d;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        if(a>=1&&a<=126&&b>=0&&b<=255&&c>=0&&c<=255&&d>=0&&d<=255){
            printf("A\n");
        }
        else if(a>=128&&a<=191&&b>=0&&b<=255&&c>=0&&c<=255&&d>=0&&d<=255){
            printf("B\n");
        }
        else if(a>=192&&a<=223&&b>=0&&b<=255&&c>=0&&c<=255&&d>=0&&d<=255){
            printf("C\n");
        }
        else if(a>=224&&a<=239&&b>=0&&b<=255&&c>=0&&c<=255&&d>=0&&d<=255){
            printf("D\n");
        }
        else if(a>=240&&a<=255&&b>=0&&b<=255&&c>=0&&c<=255&&d>=0&&d<=255){
            printf("E\n");
        }
        else{
            printf("nope\n");
        }

    }

    return 0;
}
