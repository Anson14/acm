#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int h[100000 + 5];

long long maxWater(int N) {
    int l = 0, r = N - 1;
    long long maxW = 0;
    while(l < r) {
        maxW = max<long long>(maxW, min(h[l], h[r]) * (long long)(r - l));
        h[l] < h[r] ? l++ : r--;
    }
    return maxW;
}

int main() {
    int N;
    while(scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; ++i)
            scanf("%d", &h[i]);
        printf("%lld\n", maxWater(N));
    }

    return 0;
}