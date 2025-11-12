#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

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
            return true;
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; 

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= s.size(); ++i) {
            for (auto word : wordSet) {
                if (word.size() > i) {
                    continue;
                }

                auto pos = i - word.size();
                auto size = word.size();
                auto subStr = s.substr(pos, size);
                if (subStr != word) {
                    continue;
                }

                if (!dp[pos]) {
                    continue;
                }

                dp[i] = true;
                break;
            }
        }

        return dp[s.size()];
    } 
};
// @lc code=end

int main() {
    string str = "leetcode";
    vector<string> dictWord{"leet", "code"};
    Solution sol;
    sol.wordBreak(str, dictWord);
    return 0;
}