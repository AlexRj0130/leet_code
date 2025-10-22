#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        } 

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res(1, intervals[0]); 
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[0] <= intervals[i][0] && res.back()[1] >= intervals[i][0]) {
                auto backTmp = res.back();
                res.pop_back();
                backTmp[1] = backTmp[1] >= intervals[i][1] ? backTmp[1] : intervals[i][1];
                res.push_back(backTmp);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
// @lc code=end

