class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        
        // Iterate from the least significant digit
        for (int i = n - 1; i >= 0; i--) {
            // Increment the current digit
            digits[i]++;
            
            // If there is no carry, return the result
            if (digits[i] <= 9) {
                return digits;
            }
            
            // If there is a carry, set the current digit to 0 and continue with the next digit
            digits[i] = 0;
        }
        
        // If we reach here, it means there is a carry in the most significant digit
        int[] result = new int[n + 1];
        result[0] = 1; // Set the most significant digit to 1
        return result;
    }
}
