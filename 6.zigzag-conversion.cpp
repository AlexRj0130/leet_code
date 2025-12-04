#include <string>

using namespace std;

/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        } 

        string res;
        int initStep = (numRows - 1) * 2;

        for (int i = 0; i < numRows; ++i) {
            int midStep = initStep - 2 * i;
            for (int j = i; j < s.size(); j += initStep) {
                res += s[j];
                if (midStep != 0 && (!(midStep == initStep)) && j + midStep < s.size()) {
                    res += s[j + midStep];
                }
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    // string s = "PAYPALISHIRING"; // PAHNAPLSIIGYIR
    string s = "PAYPALISHIRING"; // PINALSIGYAHRPI
    int numRows = 4;
    Solution sol;
    auto res = sol.convert(s, numRows);
    return 0;
}

