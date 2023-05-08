# 4. Median of Two Sorted Arrays
## Problem Statement
Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.
The overall run time complexity should be `O(log (m+n))`.
## Solution
+ To find the median of two sorted arrays, we need to first merge the two arrays into one sorted array and then find the median of the merged array. However, we can do better than O(m+n) time complexity by using a divide-and-conquer approach.
+ The idea is to divide both arrays into two halves, such that the elements in the left half are smaller than the elements in the right half. Then, we can find the median of the merged array by finding the median of the two halves. If the length of the merged array is odd, the median is the middle element. If the length is even, the median is the average of the middle two elements.

```
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
```
This is the function definition. It takes in two vectors `nums1` and `nums2` which are the sorted arrays, and returns a double value which is the median of the two sorted arrays.

```
int m = nums1.size();
int n = nums2.size();
if (m > n) {
    return findMedianSortedArrays(nums2, nums1);
}
```
Here, we first calculate the sizes of both arrays and store them in variables `m` and `n`. We then check if the length of the first array is greater than the length of the second array. If it is, we swap the arrays to ensure that the first array is always smaller. This is because the algorithm assumes that the first array is always smaller.

```
int imin = 0, imax = m;
while (imin <= imax) {
    int i = (imin + imax) / 2;
    int j = (m + n + 1) / 2 - i;
    if (i < m && nums2[j-1] > nums1[i]) {
        imin = i + 1;
    } else if (i > 0 && nums1[i-1] > nums2[j]) {
        imax = i - 1;
    } else {
        int max_left = 0;
        if (i == 0) {
            max_left = nums2[j-1];
        } else if (j == 0) {
            max_left = nums1[i-1];
        } else {
            max_left = max(nums1[i-1], nums2[j-1]);
        }
        if ((m + n) % 2 == 1) {
            return max_left;
        }
        int min_right = 0;
        if (i == m) {
            min_right = nums2[j];
        } else if (j == n) {
            min_right = nums1[i];
        } else {
            min_right = min(nums1[i], nums2[j]);
        }
        return (max_left + min_right) / 2.0;
    }
}
```
This is the main part of the code where the actual algorithm is implemented.

We initialize two variables, `imin` and `imax`, which represent the minimum and maximum indices of the first array that we need to consider. We start with `imin = 0` and `imax = m`, which means that we are considering the entire first array.

In each iteration of the loop, we calculate the indices `i` and `j` such that `i + j = (m + n + 1) / 2`, and the elements in the left half of the merged array are `nums1[0...i-1]` and `nums2[0...j-1]`, while the elements in the right half are `nums1[i...m-1]` and `nums2[j...n-1]`.

We then check if `nums2[j-1] > nums1[i]`. If it is, we need to move `i` to the right to make the left half of the merged array larger. Similarly, if `nums1[i-1] > nums2[j]`, we need to move `i` to the left to make the left half smaller.

If we find the correct `i` such that all the elements in the left half are smaller than all the elements in the right half, we calculate the median. If the length of the merged array is odd, the
