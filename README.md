# MulThdMergeSort
简单的基于多线程归并排序方法。

## Test
`g++ -o MulThdMgSortTest MulThdMgSortTest.cpp -std=c++11`

## Notice
oldMerge是O(n)的单线程归并排序后的数据合并，newMerge是O(nlogn)的多线程归并排序后的数据合并，newMerge目前只支持数组长度是2的幂次的情况。
