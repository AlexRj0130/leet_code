#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        } 
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dpSum(nums.size() + 1, 0);
        dpSum[1] = nums[0];
    
        vector<bool> dpFlag(nums.size() + 1, false);
        dpFlag[1] = true;

        for (int i = 2; i <= nums.size(); ++i) {
            if (dpFlag[i - 1]) {
                if (dpSum[i - 1] > dpSum[i - 2] + nums[i - 1]) {
                    dpSum[i] = dpSum[i - 1];
                    dpFlag[i] = false;
                } else {
                    dpSum[i] = dpSum[i - 2] + nums[i - 1];
                    dpFlag[i] = true;
                }
            } else {
                dpSum[i] = dpSum[i - 1] + nums[i - 1]; 
                dpFlag[i] = true;
            }
        }

        return dpSum[nums.size()];
    }
};
// @lc code=end

