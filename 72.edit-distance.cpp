#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        initDp(word1.size(), word2.size());
        stateTransfer(word1, word2);
        return dp[word1.size()][word2.size()];
    }
private:
    void stateTransfer(const string &word1, const string &word2) {
        auto rowSize = word1.size();
        auto colSize = word2.size();

        for (int i = 1; i <= rowSize; ++i) {
            for (int j = 1; j <= colSize; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }

    void initDp(int rowSize, int colSize) {
        dp = vector<vector<int>>(rowSize + 1, vector<int>(colSize + 1, 0));
        for (int i = 0; i <= rowSize; ++i) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= colSize; ++j) {
            dp[0][j] = j;
        }
    }

private:
    vector<vector<int>> dp;
};
// @lc code=end

