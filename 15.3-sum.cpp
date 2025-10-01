#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (nums[0] > 0 || nums[nums.size() - 1] < 0) {
            return {};
        }

        vector<vector<int>> res;
        for (int i = 0; i < nums.size() -2;) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(++j < nums.size() - 1 && nums[j] == nums[j-1]) {}
                    while(--k > j && nums[k] == nums[k+1]) {}
                } else if (sum < 0) {
                    while(++j < nums.size() - 1 && nums[j] == nums[j-1]) {}
                } else {
                    while(--k > j && nums[k] == nums[k+1]) {}
                }
            }

            while(++i < nums.size() - 2 && nums[i] == nums[i-1]) {}
        }

        return res; 

    }
};
// @lc code=end

int main() {
    vector<int> nums = {-100,-70,-60,110,120,130,160};

    Solution sol;
    sol.threeSum(nums);

    return 0;
}

