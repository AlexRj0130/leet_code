#include <vector>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        if (nums.size() <= 0) {
            return res;
        } 

        sort(nums.begin(), nums.end());
        vector<int> trace;
        dfs(res, nums, trace, 0); 

        return res;
    }
private:
    void dfs(vector<vector<int>> &res, const vector<int>& nums, vector<int>& trace, int index) {
        if (index >= nums.size()) {
            return;
        }

        int preVal = 1000;
        for (int i = index; i < nums.size(); ++i) {
            auto curVal = nums[i];
            if (curVal == preVal) {
                continue;
            }

            trace.push_back(curVal);
            res.push_back(trace);
            preVal = curVal;

            dfs(res, nums, trace, i + 1);
            trace.pop_back();
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1,2,2};
    Solution sol;
    sol.subsetsWithDup(nums);
    return 0;
}