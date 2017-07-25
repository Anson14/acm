#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>

using namespace std;

int n;
string a[2];
string c[2];
bool b[2];

int main() {
	ios::sync_with_stdio(false);
    // memset(b, 0, 1002);
    fill(b, b+2, false);
    cin>> a[0]>> a[1];
    b[0] = true;
    b[1] = true;
    cout<< a[0]<< " "<< a[1]<< endl;

    cin>> n;
    while (n--) {
        cin>> c[0]>> c[1];
        for (int i = 0; i < 2; i++){
            if (c[i] == a[0]) {
                cout<< a[1];
                if(i) {
                    cout << endl;
                } else {
                    cout<< " ";
                }
                b[0] = false;
            }
            else if (c[i] ==  a[1]) {
                cout<< a[0];
                if (i) {
                    cout<< endl;
                } else {
                    cout<< " ";
                }
                b[1] = false;
            } 
            else {
                if (!b[0]) {
                    a[0] = c[i];
                    b[0] = true;
                } else if (!b[1]){
                    a[1] = c[i];
                    b[1] = true;
                }
                cout<< c[i];
                if (i) {
                    cout<< endl;
                } else {
                    cout<< " ";
                }
            }
        }
    }


	
	return 0;
}