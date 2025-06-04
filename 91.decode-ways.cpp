#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }

        if (s[0] == '0') {
            return 0;
        }

        vector<int> dpVec(s.size() + 1, 0);
        dpVec[0] = dpVec[1] = 1;
        for (int i = 2; i <= s.size(); ++i) {
            int one = s[i - 1] - '0';
            int two = stoi(s.substr(i - 2, 2));

            if (one >= 1 && one <= 9) {
                dpVec[i] += dpVec[i - 1];
            }

            if (two >= 10 && two <= 26) {
                dpVec[i] += dpVec[i - 2];
            }
        }

        return dpVec[s.size()];
    }
};
// @lc code=end

