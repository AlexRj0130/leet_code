#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        } 

        vector<int> record;
        record.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > record.back()) {
                record.push_back(nums[i]);
                continue;
            } 

            auto firstGE = lower_bound(record.begin(), record.end(), nums[i]);
            if (firstGE != record.end()) {
                *firstGE = nums[i];
            }
        }

        return record.size();
    }
};
// @lc code=end

int main() {
    vector<int> nums{10,9,2,5,3,7,101,18};
    Solution sol;

    sol.lengthOfLIS(nums);
    return 0;
}

