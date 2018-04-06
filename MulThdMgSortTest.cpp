#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include <windows.h>

#include "MulThdMgSort.h"

using namespace std;

int s[100010];
int main() {
    freopen("data.in", "r" ,stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d\n", s+i);
    }
    printf("Read data successfully.\n");
    MulThdMgSort<int> mtms(n, s);
    printf("Generate class successfully.\n");
    // pthread_t pid;
    // void *status;
    // int l(0), r(mtms.getLength());
    // pthread_create(&pid, NULL, mtms.sort, l, r);
    // pthread_join(pid, &status);
    mtms.sortByOldMg();
    mtms.print();
    return 0;
}