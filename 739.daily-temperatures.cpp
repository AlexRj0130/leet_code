#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto tSize = temperatures.size();

        vector<int> minTempIndex;
        vector<int> res(tSize, 0);

        for (int i = tSize - 1; i >= 0; --i) {
            auto curTemp = temperatures[i];
            while (minTempIndex.size() > 0 && curTemp >= temperatures[minTempIndex.back()]) {
                minTempIndex.pop_back();
            }

            if (minTempIndex.size() > 0) {
                res[i] = minTempIndex.back() - i;
            }
            minTempIndex.push_back(i);
        }

        return res;
    }
};
// @lc code=end

