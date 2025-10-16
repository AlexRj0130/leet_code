#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> status(nums.size(), false);
        backtrace(nums, path, status, res);

        return res;
    }
private:
    void backtrace(const vector<int>& nums, 
        vector<int> &path, 
        vector<bool>& status, 
        vector<vector<int>> &res) {
            if (path.size() == nums.size()) {
                res.push_back(path);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (status[i]) {
                    continue;
                }

                path.push_back(nums[i]);
                status[i] = true;
                backtrace(nums, path, status, res);

                path.pop_back();
                status[i] = false;
            }
    }
};
// @lc code=end

