#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, res = 1000000;
        while (right < nums.size()) {
            while (right < nums.size() && sum < target) {
                sum += (nums[right++]);
                if (sum >= target) {
                    res = min(res, right - left);
                }
            }

            if (left < nums.size()) {
                sum -= (nums[left++]); 
                if (sum >= target) {
                    res = min(res, right - left);
                } 
            }

            while (left < right && (sum - nums[left] >= target)) {
                sum -= (nums[left++]);
                if (sum >= target) {
                    res = min(res, right - left);
                } 
            }
        }
        return res >= 1000000 ? 0 : res;
    }
};
// @lc code=end

int main() {
    auto nums = vector<int>{2,3,1,2,4,3};
    int target = 7;
    
    Solution sol;
    sol.minSubArrayLen(target, nums);

    return 0;
}