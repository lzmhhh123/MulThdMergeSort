#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));
    freopen("data.in", "w", stdout);
    int n = 100000;
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", rand());
    }
    return 0;
}