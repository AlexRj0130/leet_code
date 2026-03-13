#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> trace;
        backTrace(1, 0, n, 0, k, res, trace);
        return res;
    }
private:
    void backTrace(int nextNum, int preSum, const int targetSum, const int preDepth, const int targetDepth, vector<vector<int>> &res, vector<int> &trace) {
        if (preDepth >= targetDepth || preSum >= targetSum) {
            return;
        }

        int curDepth = preDepth + 1;

        for (int num = nextNum; num <= 9; ++num) {
            int curSum = preSum + num;
            trace.push_back(num);
            if (curSum > targetSum) {
                trace.pop_back();
                break;
            } else if (curSum == targetSum) {
                if (curDepth == targetDepth) {
                    res.push_back(trace);
                } 
                trace.pop_back();
                break;
            } else {
                if (curDepth == targetDepth) {
                    trace.pop_back();
                    continue;
                }
                backTrace(num + 1, curSum, targetSum, curDepth, targetDepth, res, trace);
                trace.pop_back();
            }
        }
    }
};
// @lc code=end

int main() {


}

