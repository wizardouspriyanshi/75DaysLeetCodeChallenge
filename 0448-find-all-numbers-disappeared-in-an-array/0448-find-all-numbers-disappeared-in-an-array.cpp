class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        // Step 1: Mark visited indices
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1; // Map value to index
            if (nums[index] > 0) {
                nums[index] = -nums[index]; // Mark as negative
            }
        }
        
        // Step 2: Find indices that are still positive
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1); // Index i corresponds to value i + 1
            }
        }
        
        return result;
    }
};