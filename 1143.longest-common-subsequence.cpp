#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size(), size2 = text2.size(); 
        if (size1 <= 0 || size2 <= 0) {
            return 0;
        }

        auto dp = vector<vector<int>>(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[size1][size2];
    }
};
// @lc code=end

