#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; // position for non-zero

        // Step 1: move non-zero elements forward
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }

        // Step 2: fill remaining with 0
        while(i < nums.size()) {
            nums[i] = 0;
            i++;
        }
    }
};