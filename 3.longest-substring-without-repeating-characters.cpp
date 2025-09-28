#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }

        vector<bool> charFlag(1000, false);
        charFlag[s[0]] = true;

        int start = 0;
        int maxLen = 1;
        
        for (int i = 1; i < s.size(); ++i) {
            auto c = s[i];
            if (charFlag[c] == false) {
                charFlag[c] = true;
                maxLen = (i - start + 1) > maxLen ? (i - start + 1) : maxLen;
                continue;
            }

            for (int j = start; j < i; ++j) {
                auto cPre = s[j];
                if (cPre == c) {
                    start = j + 1;
                    break;
                }
                charFlag[cPre] = false;
            }

        }

        return maxLen; 
    }
};
// @lc code=end

