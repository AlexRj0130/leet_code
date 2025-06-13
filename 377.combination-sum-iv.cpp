#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        return count(nums, target);
    }
private:
    int count(const vector<int>& nums, int target) {
        if (nums.size() == 0 || nums[0] > target) {
            mNum2Count[target] = 0;
            return 0;
        }

        if (mNum2Count.contains(target)) {
            return mNum2Count[target];
        }

        int equalCount = 0;
        int remainCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int remain = target - num;
            if (remain < 0) {
                break;
            } else if (remain == 0) {
                ++equalCount;
                break;
            } else {
                remainCount += count(nums, remain);
            }
        }

        int res = remainCount + equalCount;
        mNum2Count[target] = res;
        return res;
    }

private:
    unordered_map<int, int> mNum2Count;
};
// @lc code=end

