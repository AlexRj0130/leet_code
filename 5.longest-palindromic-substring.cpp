#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> record(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            record[i][i] = 1;
        }

        int maxLen = 1, maxSta = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i+1; j < s.size(); ++j) {
                if (isPalindrome(s, record, i, j)) {
                    if (maxLen < (j - i + 1)) {
                        maxLen = j - i + 1;
                        maxSta = i;
                    }
                }
            }
        }

        return s.substr(maxSta, maxLen);
    }

    bool isPalindrome(const string &s, vector<vector<int>> &record, int i, int j) {
        if (record[i][j] == 1) {
            return true;
        } else if (record[i][j] == 2) {
            return false;
        }

        if (s[i] != s[j]) {
            record[i][j] = 2;
            return false;
        }

        if (j - i < 3) {
            record[i][j] = 1;
            return true; 
        }

        if (isPalindrome(s, record, i + 1, j - 1)) {
            record[i][j] = 1;
            return true;
        }

        record[i][j] = 2;
        return false;
    }
};
// @lc code=end

