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
        if (s.size() <= 0) {
            return "";
        } else if (s.size() <= 1) {
            return s.substr(0, 1);
        }

        initDpVec(s);

        int maxLong = 1;
        string res = s.substr(0, 1);
        for (int j = 1; j < s.size(); ++j) {
            for (int i = j - 1; i >= 0; --i) {
                dpVec[i][j] = ((j - i == 1 ) || dpVec[i + 1][j - 1]) && s[i] == s[j];
                if (dpVec[i][j] && j - i + 1 > maxLong) {
                    maxLong = j - i + 1;
                    res = s.substr(i, maxLong);
                }
            }
        }

        return res;
    }
private:
    void initDpVec(const string &s) {
        int size = s.size();
        if (size <= 1) {
            return;
        }

        vector<bool> subVec(size, false);
        dpVec = vector<vector<bool>>(size, subVec);
        for (int i = 0; i < size; ++i) {
            dpVec[i][i] = true;
        }
    }
private:
    vector<vector<bool>> dpVec;
};
// @lc code=end

int main() {
    string s = "babad";
    Solution sol;
    auto res = sol.longestPalindrome(s);
    return 0;
}

