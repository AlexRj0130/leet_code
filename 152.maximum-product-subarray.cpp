#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums[0];
        }

        vector<int> dpMax(nums.size(), 0);
        vector<int> dpMin(nums.size(), 0);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            auto num = nums[i];
            dpMax[i] = max({dpMax[i - 1] * num, dpMin[i - 1] * num, num});
            dpMin[i] = min({dpMax[i - 1] * num, dpMin[i - 1] * num, num});
            res = max({dpMax[i], dpMin[i], res});
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<int> data({-2, 3, -4});
    Solution sol;
    auto res = sol.maxProduct(data);
    return 0;
}

