#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    long long  n, a, b, c;
    while (cin>> n>> a>> b>> c) {
//        long long  aa = 0, bb = 0, cc = 0;

//        long long  u = min(x,min(y,z));
        int yyy = n % 4;
        if (yyy == 0) {
            cout<< 0<< endl;
        } else if (yyy == 1) {
            long long  x = a*3;
            long long  y = b + a;
            long long  z = c;
            long long  ddd = b*2 + c;
            long long  hhh = min(x,min(y,min(z,ddd)));
            cout<< hhh<< endl;   
            } else if (yyy == 2) {
            long long  x = a*2;
            long long  y = b;
            long long  z = c*2;
            long long  hhh = min(x,min(y,z));
            cout<< hhh<< endl;   
        } else {
            long long  x = a;
            long long  y = b + c;
            long long  z = c*3;
            long long  hhh =  min(x, min(y, z));
            cout<< hhh<< endl;   
        }

    }

    return 0;
}