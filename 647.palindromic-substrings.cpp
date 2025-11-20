#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() <= 1) {
            return s.size();
        } 

        int res = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                bool tmp = false;
                if (j == i) {
                    tmp = true;
                } else if (i - j <= 2) {
                    tmp = (s[i] == s[j]);
                } else if (i - j > 2) {
                    tmp = (s[i] == s[j]) && dp[j+1][i-1];
                }

                if (tmp) {
                    ++res;
                    dp[j][i] = true;
                }
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    string s = "abc";
    Solution sol;
    sol.countSubstrings(s);
    return 0;
}

