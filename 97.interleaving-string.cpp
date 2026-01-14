#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        if (size1 + size2 != size3) {
            return false;
        }

        vector<vector<bool>> dp(size1 + 1, vector<bool>(size2 + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= size1; ++i) {
            dp[i][0] = (s1[i-1] == s3[i-1] && dp[i-1][0]);
        } 
        for (int j = 1; j <= size2; ++j) {
            dp[0][j] = (s2[j-1] == s3[j-1] && dp[0][j-1]);
        }

        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j) {
                auto flag1 = (s1[i-1] == s3[i + j - 1] && dp[i-1][j]);
                auto flag2 = (s2[j-1] == s3[i + j - 1] && dp[i][j-1]);
                dp[i][j] = (flag1 || flag2);
            }
        }

        return dp[size1][size2];
    }
};
// @lc code=end

int main() {
    Solution sol;
    auto res = sol.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;    
}

