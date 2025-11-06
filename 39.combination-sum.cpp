#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() <= 0) {
            return {};
        } 

        sort(candidates.begin(), candidates.end());

        vector<int> record;
        vector<vector<int>> res;

        dfs(candidates, 0, target, 0, record, res);

        return res;
    }

private:
    void dfs(const vector<int>& candidates, int start, int target, int sum, vector<int> &record, vector<vector<int>> &res) {
        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            int tmpSum = sum + candidates[i];
            record.push_back(candidates[i]);
            if (tmpSum < target) {
                dfs(candidates, i, target, tmpSum, record, res);
                record.pop_back();
            } else if (tmpSum == target) {
                res.push_back(record);
                record.pop_back();
                return;
            } else {
                record.pop_back();
                return;
            }
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums{2, 3, 6, 7};

    Solution sol;
    sol.combinationSum(nums, 7);

    return 0;
}
