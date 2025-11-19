#include <vector>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int curSum = 0;
        unordered_map<int, int> prefixSum;

        prefixSum[0] = 1;

        for (auto num : nums) {
            curSum += num;
            if (prefixSum.contains(curSum - k)) {
                count += prefixSum[curSum -k];
            }

            ++prefixSum[curSum];
        }

        return count;
    }
};
// @lc code=end

