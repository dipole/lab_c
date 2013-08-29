#include <cstdio>
/*
 * 传统的二分查找，数组有序且没有重复
 */
int binary_S(int *a, int n, int key)
{
    int l = 0, r = n-1;
    int mid;
    while (l <= r){
        mid = (l + r) >> 1;
        if (a[mid] == key)
            return mid;
        if (a[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
/*
 * 找出等于key且下标最小的值的下标，输入数组有序
 */
int binary_S2(int *a, int n, int key)
{
    int l = 0, r = n-1;
    while (l < r){
        int mid = (l + r) >> 1;
        if (a[mid] >= key)
            r = mid;
        else
            l = mid + 1;
    }
    if (a[r] == key)
        return r;
    return -1;
}
/*
 * 找出等于key且下标最大的值的下标，输入数组有序
 */
int binary_S3(int *a, int n, int key)
{
    int l = 0, r = n-1;
    while (l < r){
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= key)
            l = mid;
        else
            r = mid - 1;
    }
    if (a[l] == key)
        return l;
    return -1;
}
/*
 * 找出一个先递增后递减数列的最大值
 */
int binary_S4(int *a, int n)
{
    int l = 0, r = n-1;
    int mid;
    while (l <= r){
        mid = (l + r) >> 1;
        if (mid > 0 && a[mid-1] > a[mid])
            r = mid - 1;
        else if (mid < n-1 && a[mid+1] > a[mid])
            l = mid + 1;
        else
            return a[mid];
    }
}
