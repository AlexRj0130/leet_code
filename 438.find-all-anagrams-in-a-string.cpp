#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> charTargetCount(26, 0); 
        int totalCount;
        for (auto ch : p) {
            ++charTargetCount[ch - 'a'];
            ++totalCount;
        }

        vector<int> res;
        for (int left = 0; left < s.size(); ++left) {
            vector<int> charCurCount(26, 0);
            int curCount = 0;

            for (int right = left; right < s.size(); ++right) {
                auto rightChar = s[right];
                auto rightCharIndex = rightChar - 'a';
                if (charTargetCount[rightCharIndex] > 0) {
                    if (charCurCount[rightCharIndex] < charTargetCount[rightCharIndex]) {
                        ++charCurCount[rightCharIndex];
                        ++curCount;
                    } else {
                        break;
                    }

                    if (curCount == totalCount) {
                        res.push_back(left); 
                        break;
                    }
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

