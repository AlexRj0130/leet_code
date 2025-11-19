#include <vector>

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
        if (nums.size() <= 0) {
            return 0;
        } 

        initDP(nums);
        iterateDP(nums); 
        auto res = countDP(nums, k);
        return res;
    }
private:
    void initDP(const vector<int>& nums) {
        if (nums.size() <= 0) {
            return;
        }

        auto numSize = nums.size();
        dp = vector<vector<int>>(numSize, vector<int>(numSize, 0));
        for (int i = 0; i < numSize; ++i) {
            dp[i][i] = nums[i];
        }
    }

    void iterateDP(const vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                dp[i][j] = dp[i][j-1] + nums[j]; 
            }
        }
    }

    int countDP(const vector<int>& nums, int target) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (dp[i][j] == target) {
                    ++res;
                }
            }
        }
        return res;
    }
private:
    vector<vector<int>> dp;
};
// @lc code=end

