class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0]; // Initialize currentMax to the first element.
        int globalMax = nums[0];  // Initialize globalMax to the first element.
        
        // Iterate through the array starting from the second element.
        for (int i = 1; i < nums.size(); i++) {
            // Calculate the maximum between the current element and the sum of current element and currentMax.
            currentMax = max(nums[i], currentMax + nums[i]);
            
            // Update the globalMax if the currentMax is greater.
            globalMax = max(globalMax, currentMax);
        }
        
        return globalMax;
    }
};
