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
        vector<int> record; 
        vector<vector<int>> res; 
        res.push_back({});

        backtracing(nums, 0, record, res);
        return res;
    }
private:
    void backtracing(const vector<int>& nums, int index, vector<int> record, vector<vector<int>> &res) {
        if (index >= nums.size()) {
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            record.push_back(nums[i]);
            res.push_back(record);

            backtracing(nums, i+1, record, res);

            record.pop_back();
        }
    }
};
// @lc code=end

