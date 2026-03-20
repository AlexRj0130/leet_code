#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> vecCount(1000 + 1, 0);
        for (auto item : citations) {
            mark(vecCount, item);
        }

        int res = 0;
        for (int i = 0; i < vecCount.size(); ++i) {
            if (vecCount[i] >= i) {
                res = i;
            }
        }

        return res;
    }
private:
    void mark(vector<int> &vecCount, int count) {
        for (int i = 0; i <= count; ++i) {
            ++vecCount[i];
        }
    }
};
// @lc code=end

