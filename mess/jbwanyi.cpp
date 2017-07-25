#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}a[1000+10];
bool cmp(node a,node b){
    return a.a-a.c < b.a-b.c;
}
int main()
{
    int T;
    int k,flag,cnt=0;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0 ; i < n ; i ++){
            cin >> a[i].a >> a[i].b >> a[i].c;
            sum += a[i].c;
        }
        int time;
        cin >> time;
        if(sum > time)
            cout << "Oh,my god!" << endl;
        else{
            sort(a,a+n,cmp);
            int cnt = 0;
            for(int i = 0 ; i < n ; i ++){
                cout<< "a"<< a[i].a<< "  b"<< a[i].c<< "  sum"<< sum<< endl;
                if(sum - a[i].c + a[i].a <= time){
                    sum = sum - a[i].c + a[i].a;
                    cnt ++;
                }else{
                    break;
                
                }
            }
            cout << cnt << endl;
        }
        
    }
    
    return 0;
}