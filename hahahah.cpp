#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int a[10]; 

int main() {
    int n = 10;
    for (int i = 0; i < n; i++) {
        cin>> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        for (int j = i; j < n; j++) {
            if (temp < a[j]) {
                swap(temp, a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout<< a[i] << " ";
    }

    getchar();

    return 0;
}