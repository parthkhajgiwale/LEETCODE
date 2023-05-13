class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
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
