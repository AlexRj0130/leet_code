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
        unordered_map<string, bool> existMap;
        dfs(res, nums, trace, 0, existMap); 

        return res;
    }
private:
    void dfs(vector<vector<int>> &res, const vector<int>& nums, vector<int>& trace, int index, unordered_map<string, bool> &existMap) {
        if (index >= nums.size()) {
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            trace.push_back(nums[i]);
            auto traceKey = vector2string(trace);
            if (existMap.find(traceKey) == existMap.end()) {
                res.push_back(trace);
                existMap[traceKey] = true;
            }
            dfs(res, nums, trace, i + 1, existMap);
            trace.pop_back();
        }
    }

    string vector2string(const vector<int> &vec) {
        string res = "";
        for (auto &item : vec) {
            res = res + to_string(item) + ",";
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1,2,2};
    Solution sol;
    sol.subsetsWithDup(nums);
    return 0;
}