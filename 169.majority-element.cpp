#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = 0, targetTimes = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            if (targetTimes == 0) {
                target = nums[i];
                ++targetTimes;
            } else {
                if (target == nums[i]) {
                    ++targetTimes;
                } else {
                    --targetTimes;
                }
            }
        }

        return target;
    }
};
// @lc code=end

