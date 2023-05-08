# 1. Two Sum 
## Problem Statement
Given an array of integers `nums` and an integer `target` return indices of the two numbers such that they add up to `target`.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

```Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

## Solution 
+ This implementation uses an unordered map to store the indices of each number in the array. For each number in the array, it checks if the complement (the target minus the number) is already in the map. If it is, it returns the current index and the index of the complement. If it isn't, it adds the current number and its index to the map and continues to the next number in the array.
+ Note that this implementation assumes that each input has exactly one solution and returns the answer in any order.

1. The `twoSum` function takes two inputs: an array of integers called `nums`, and an integer called `target`, and returns a vector of integers.

```
vector<int> twoSum(vector<int>& nums, int target) {
```

2. The function declares an unordered map called `numToIndex` which will store the indices of the numbers in `nums`.

```
unordered_map<int, int> numToIndex;
```

3. The function then loops through each element `nums[i]` in `nums`.

```
for (int i = 0; i < nums.size(); i++) {
```

4. For each element `nums[i]`, the function computes the complement `complement = target - nums[i]`.

```
int complement = target - nums[i];
```

5. The function then checks if the complement `complement` is already in the `numToIndex` map by calling the `count` function.

```
if (numToIndex.count(complement)) {
```

6. If the complement is in the map, the function returns a vector containing the index of the complement and the current index `i`.

```
return { numToIndex[complement], i };
```

7. If the complement is not in the map, the function adds the current number `nums[i]` and its index `i` to the map.

```
numToIndex[nums[i]] = i;
```

8. After the loop finishes, the function returns an empty vector if no two numbers in `nums` add up to the target.

```
return {};
```

In summary, the function uses an unordered map to keep track of the indices of the numbers in the input array. 
It loops through each number in the array and checks if its complement (the target minus the number) is already in the map. 
If it is, the function returns the indices of the two numbers that add up to the target. 
If not, it adds the number and its index to the map and continues to the next number. 
If no two numbers add up to the target, the function returns an empty vector.

