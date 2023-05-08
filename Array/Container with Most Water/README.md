# 11. Container With Most Water
## Problem Statement
You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
## Solution
```
class Solution {
public:
    int maxArea(vector<int>& height) {
```
Here we define a class `Solution` with a function `maxArea` which takes a vector of integers as input.

```
int n = height.size();
int left = 0, right = n-1;
int max_area = 0;
```
We initialize `n` to be the length of the input vector `height`. We also initialize two pointers `left` and `right` to the beginning and end of the input vector respectively. We also initialize a variable `max_area` to 0, which we will update as we traverse the array.

```
while (left < right) {
    int area = min(height[left], height[right]) * (right - left);
    max_area = max(max_area, area);
```
We traverse the array using a `while` loop as long as the `left` pointer is less than the `right` pointer. Within the loop, we calculate the area between the two pointers using the formula `min(height[left], height[right]) * (right - left)`. We then update the maximum area seen so far using `max(max_area, area)`.

```
if (height[left] < height[right]) {
    left++;
} else {
    right--;
}
```
We then move the pointer pointing to the smaller line inwards, since moving the pointer pointing to the larger line inwards cannot increase the area and would only result in a smaller area. We do this by checking if the height at the `left` pointer is less than the height at the `right` pointer. If so, we move the `left` pointer one position to the right. Otherwise, we move the `right` pointer one position to the left.

```
}
return max_area;
}
};
```
Finally, we return the maximum area seen during the traversal of the input vector.
