#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() <= 0) {
            return false;
        }

        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            for (const auto & word: wordDict) {
                int staIndex = i - word.size() + 1;
                if (staIndex < 0) {
                    continue;
                }
                auto tmp = s.substr(staIndex, word.size());
                if (tmp == word) {
                    if (staIndex <= 0) {
                        dp[i] = true;
                        break;
                    } else if (dp[staIndex - 1]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.size() - 1];
    } 
};
// @lc code=end

int main() {
    // string str = "leetcode";
    // vector<string> dictWord{"leet", "code"};

    string str = "code";
    vector<string> dictWord{"leet", "code"};

    Solution sol;
    auto res = sol.wordBreak(str, dictWord);
    cout << res << endl;
    return 0;
}