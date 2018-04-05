#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include <windows.h>

#include "MulThdMgSort.h"

using namespace std;

int main() {
    int s[20] = {434, 31231, 222, 111, 123, 1, 200, 12345};
    MulThdMgSort<int> mtms(8, s);
    // pthread_t pid;
    // void *status;
    // int l(0), r(mtms.getLength());
    // pthread_create(&pid, NULL, mtms.sort, l, r);
    // pthread_join(pid, &status);
    mtms.sort();
    mtms.print();
    return 0;
}