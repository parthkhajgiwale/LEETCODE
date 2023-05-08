# 15. 3Sum
## Problem Statement
Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j, i != k, and j != k`, and `nums[i] + nums[j] + nums[k] == 0`.
Notice that the solution set must not contain duplicate triplets.
## Solution
To solve the problem, we can follow the following approach:
1. Sort the input array in non-descending order. This will help us eliminate duplicates in the final solution set.
2. For each number in the input array, use two pointers to find all pairs of numbers that sum to the negation of the current number.
3. Add each triplet to the solution set if it is not already present.

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
```

This is the start of the `threeSum` function. It takes an input vector of integers `nums` and returns a vector of vector of integers `result`. We first sort the input array in non-descending order using the `sort` function from the `<algorithm>` header. This will help us eliminate duplicates in the final solution set.

```
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
            
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0 || (l > i + 1 && nums[l] == nums[l-1])) {
                    // current sum is too small or left pointer has a duplicate
                    l++;
                } else if (sum > 0 || (r < n - 1 && nums[r] == nums[r+1])) {
                    // current sum is too large or right pointer has a duplicate
                    r--;
                } else {
                    // found a valid triplet
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        
        return result;
    }
};
```

We then iterate through the input array `nums` using the loop variable `i`, and for each `i`, we use two pointers `l` and `r` to find all pairs of numbers that sum to the negation of the current number. We start `l` at `i+1` and `r` at the end of the array.

Inside the loop, we check if the current `i` is a duplicate. If it is, we skip it to avoid generating duplicate triplets. We then check the sum of the current triplet. If it is less than zero, we increment `l`, because we want a larger sum. If it is greater than zero, we decrement `r`, because we want a smaller sum. If the sum is zero, we found a valid triplet and add it to the result set `result`.

Finally, we return the result set. The time complexity of the code is O(n^2), where n is the size of the input array, and the space complexity is O(1), since we are only using constant extra space to store the solution set.
