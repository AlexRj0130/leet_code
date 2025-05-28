#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; 
        res.push_back(vector<int>{});
        getSubsets(nums, vector<int>{}, 0, res);
        return res;
    }
private:
    void getSubsets(const vector<int> &nums, vector<int> preRes, int next, vector<vector<int>> &res) {
        if (next >= nums.size()) {
            return;
        }

        for (int i = next; i < nums.size(); ++i) {
            vector<int> tmp = preRes;
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            getSubsets(nums, tmp, i + 1, res);
        }
    }
};
// @lc code=end

