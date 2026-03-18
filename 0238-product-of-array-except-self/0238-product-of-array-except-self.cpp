#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, 1);
        
        // Step 1: Calculate Prefix Products
        // ans[i] will contain the product of all elements to the left of i
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        // Step 2: Calculate Suffix Products on the fly
        // Use a variable 'rightProduct' to track the product of elements to the right
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            // Multiply the existing prefix product by the current suffix product
            ans[i] = ans[i] * rightProduct;
            // Update suffix product for the next element to the left
            rightProduct *= nums[i];
        }
        
        return ans;
    }
};