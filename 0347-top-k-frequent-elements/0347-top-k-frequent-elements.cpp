#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> counts;
        
        // 1. Count frequencies
        for (int num : nums) {
            counts[num]++;
        }
        
        // 2. Create buckets: index represents frequency
        // buckets[i] contains a list of numbers that appear 'i' times
        std::vector<std::vector<int>> buckets(n + 1);
        for (auto const& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }
        
        // 3. Collect the k most frequent elements
        std::vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};