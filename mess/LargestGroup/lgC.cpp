#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

const int maxnum=101;
bool array[maxnum][maxnum];
bool use[maxnum]; //进入团的标号
int cn,bestn,p,e;

void dfs(int i)
{
    int j;
    bool flag;

    if(i>p)
    {
        bestn=cn;
        printf("%d\n",bestn);
        for(j=1;j<=p;j++)
            if(use[j])
                printf("%d ",j);
        printf("\n");
        return ;
    }

    flag=true;
    for(j=1;j<i;j++)
        if(use[j]&&!array[j][i])
        {
            flag=false;
            break;
        }
    if(flag)
    {
        cn++;
        use[i]=true;
        dfs(i+1);
        cn--;
    }
    if(cn+p-i>bestn)  //剪枝
    {
        use[i]=false;
        dfs(i+1);
    }
}

int main()
{
    int num, u, v = 1;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    //scanf("%d", &num);
    cin>> num;
    while(v--) {
        clr(a);
        clr(used);
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                cin>> u; 
                if (u) {
                    a[i][j] = true;
                }
            }
        }
        cin>> u;
        cn = bestn = 0;
        dfs(1);
        //printf ("%d\n", bestn);
        cout<< bestn<< endl;
    }



    return 0;
}
