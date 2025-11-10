#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) {
            return 0;
        } 

        int rowSize = matrix.size(), colSize = matrix[0].size();

        vector<vector<int>> dp(rowSize, vector<int>(colSize, 0));
        int res = 0;

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (matrix[i][j] != '0') {
                    dp[i][j] = 1;
                    res = 1;
                }
            }
        }

        for (int i = 1; i < rowSize; ++i) {
            for (int j = 1; j < colSize; ++j) {
                if (dp[i][j] == 0) {
                    continue;
                }

                dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), min(dp[i][j-1], dp[i-1][j-1])) + 1;
                res = max(res, int(dp[i][j]));
            }
        }

        return res * res;
    }
};
// @lc code=end

