#include <cstdio>
#include <vector>
#include <iostream>
#include <pthread.h>

template<class T>
struct mInfo{
    int l, r;
    T &v;
    mInfo(int ll, int rr, T &vv)
        :l(ll), r(rr), v(vv)  {}
};

template<class T>
class MulThdMgSort {

private:
    size_t length;
    std::vector<T> v;

public:
    MulThdMgSort(){}
    MulThdMgSort(size_t len, T *array);
    ~MulThdMgSort(){}

    void sort();
    void print();
    int getLength();
};


template<class T>
MulThdMgSort<T>::MulThdMgSort(size_t len, T *array) {
    length = len;
    v.resize(len);
    for (int i = 0; i < length; ++i) {
        v[i] = array[i];
    }
}

template<class T>
void* mergeSort(void* info) {
    auto arg = (mInfo<std::vector<T> >*)(info);
    int l = arg->l, r = arg->r;
    auto &v = arg->v;
    if (r - l == 1) {
        return NULL;
    } else if (r - l == 2) {
        if (v[l] > v[l + 1]) std::swap(v[l], v[l + 1]);
        return NULL;
    }

    int mid = (l + r) >> 1;
    pthread_t tid1, tid2;
    auto info1 = mInfo<std::vector<T>>(l, mid, v);
    auto info2 = mInfo<std::vector<T>>(mid, r, v);
    pthread_create(&tid1, NULL, mergeSort<T>, (void*) &info1);
    pthread_create(&tid2, NULL, mergeSort<T>, (void*) &info2);

    void *status1, *status2;
    pthread_join(tid1, &status1);
    pthread_join(tid2, &status2);

    std::vector<T>left, right;
    left.resize(mid - l);
    right.resize(r - mid);

    for (size_t i = l; i <= mid; ++i) {
        left[i-l] = v[i];
    }
    for (size_t i = mid; i < r; ++i) {
        right[i-mid] = v[i];
    }

    size_t i = 0, j = 0, k = l;
    while (i < mid-l && j < r-mid) {
        if (left[i] < right[j]) v[k++] = left[i++];
        else v[k++] = right[j++];
    }
    while (i < mid-l) v[k++] = left[i++];
    while (j < r-mid) v[k++] = right[j++];

}

template<class T>
void MulThdMgSort<T>::sort() {
    pthread_t pid;
    auto info = mInfo<std::vector<T>>(0, MulThdMgSort<T>::getLength(), v);
    pthread_create(&pid, NULL, mergeSort<T>, (void*) &info);
    void *status;
    pthread_join(pid, &status);
    return;
}

template<class T>
void MulThdMgSort<T>::print() {
    for (int i = 0; i < length; ++i) {
        std::cout << v[i] << " ";
    }
    return;
}

template<class T>
int MulThdMgSort<T>::getLength() {
    return length;
}
