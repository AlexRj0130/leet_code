#include <vector>
#include <limits>

using namespace std;

/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = numeric_limits<int>::min(), cand2 = numeric_limits<int>::min();
        int cnt1 = 0, cnt2 = 0;

        for (auto num : nums) {
            if (cand1 == num) {
                ++cnt1;
            } else if (cand2 == num) {
                ++cnt2;
            } else if (cnt1 == 0) {
                cnt1 = 1;
                cand1 = num;
            } else if (cnt2 == 0) {
                cnt2 = 1;
                cand2 = num;
            } else {
                --cnt1;
                --cnt2;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (cand1 == num) {
                ++cnt1;
            } else if (cand2 == num) {
                ++cnt2;
            }
        }

        vector<int> res;
        auto n = nums.size() / 3;
        if (cnt1 > n) {
            res.push_back(cand1);
        }
        if (cnt2 > n) {
            res.push_back(cand2);
        }

        return res;
    }
};
// @lc code=end

